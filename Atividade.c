#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* esq;
    struct node* dir;
    struct node* pai;
} No;

// Fun��o para criar um n� da �rvore bin�ria
No* criaAB(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->info = dado;
    no->esq = NULL;
    no->dir = NULL;
    no->pai = NULL;
    return no;
}

// Fun��o para criar um filho � esquerda
int filho_esq(No* raiz, int dado) {
    No* no = criaAB(dado);
    if (raiz->esq == NULL) {
        raiz->esq = no;
        raiz->esq->pai = raiz;
        return 1;
    }
    return 0;
}

// Fun��o para criar um filho � direita
int filho_dir(No* raiz, int dado) {
    No* no = criaAB(dado);
    if (raiz->dir == NULL) {
        raiz->dir = no;
        raiz->dir->pai = raiz;
        return 1;
    }
    return 0;
}

// Fun��o para inserir um n� na �rvore bin�ria
int insereAB(No* raiz, int dado) {
    if (raiz->info == dado) return 0;
    if (dado > raiz->info) {
        if (raiz->dir == NULL) {
            filho_dir(raiz, dado);
        } else {
            insereAB(raiz->dir, dado);
        }
    } else {
        if (raiz->esq == NULL) {
            filho_esq(raiz, dado);
        } else {
            insereAB(raiz->esq, dado);
        }
    }
    return 1;
}

// Fun��o para remover um n� da �rvore bin�ria
int remover(No* raiz, int dado) {
    No* pai = raiz;
    while (raiz != NULL && raiz->info != dado) {
        pai = raiz;
        if (dado > raiz->info)
            raiz = raiz->dir;
        else
            raiz = raiz->esq;
    }

    if (raiz != NULL) {
        if (raiz->esq != NULL && raiz->dir != NULL) {
            No* aux = raiz;
            pai = raiz;
            raiz = raiz->dir;
            while (raiz->esq != NULL) {
                pai = raiz;
                raiz = raiz->esq;
            }
            aux->info = raiz->info;
        } else {
            No* filho = (raiz->esq != NULL) ? raiz->esq : raiz->dir;
            if (pai->esq == raiz)
                pai->esq = filho;
            else
                pai->dir = filho;

            if (filho != NULL)
                filho->pai = pai;
            free(raiz);
        }
    }
    return 1;
}

// Fun��o de percurso pr�-ordem
void pre_ordem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

// Fun��o de percurso in-ordem
void in_ordem(No* raiz) {
    if (raiz == NULL) return;
    in_ordem(raiz->esq);
    printf("%d ", raiz->info);
    in_ordem(raiz->dir);
}

// Fun��o de percurso p�s-ordem
void pos_ordem(No* raiz) {
    if (raiz == NULL) return;
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->info);
}

// Fun��o principal
int main() {
    // For�ar o console a usar a codifica��o UTF-8
    system("chcp 65001");
    No* raiz = criaAB(10);  // Cria a raiz da �rvore

    // Inserindo dados na �rvore
    insereAB(raiz, 5);
    insereAB(raiz, 15);
    insereAB(raiz, 3);
    insereAB(raiz, 7);
    insereAB(raiz, 12);
    insereAB(raiz, 18);

    printf("Percurso Pr�-Ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf("Percurso In-Ordem: ");
    in_ordem(raiz);
    printf("\n");

    printf("Percurso P�s-Ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Remover um n� (por exemplo, o n� com valor 7)
    printf("Removendo o n� com valor 7...\n");
    remover(raiz, 7);

    printf("Percurso In-Ordem ap�s remo��o: ");
    in_ordem(raiz);
    printf("\n");

    return 0;
}
