#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* esq;
    struct node* dir;
    struct node* pai;
} No;

// Função para criar um nó da árvore binária
No* criaAB(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->info = dado;
    no->esq = NULL;
    no->dir = NULL;
    no->pai = NULL;
    return no;
}

// Função para criar um filho à esquerda
int filho_esq(No* raiz, int dado) {
    No* no = criaAB(dado);
    if (raiz->esq == NULL) {
        raiz->esq = no;
        raiz->esq->pai = raiz;
        return 1;
    }
    return 0;
}

// Função para criar um filho à direita
int filho_dir(No* raiz, int dado) {
    No* no = criaAB(dado);
    if (raiz->dir == NULL) {
        raiz->dir = no;
        raiz->dir->pai = raiz;
        return 1;
    }
    return 0;
}

// Função para inserir um nó na árvore binária
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

// Função para remover um nó da árvore binária
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

// Função de percurso pré-ordem
void pre_ordem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

// Função de percurso in-ordem
void in_ordem(No* raiz) {
    if (raiz == NULL) return;
    in_ordem(raiz->esq);
    printf("%d ", raiz->info);
    in_ordem(raiz->dir);
}

// Função de percurso pós-ordem
void pos_ordem(No* raiz) {
    if (raiz == NULL) return;
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->info);
}

// Função principal
int main() {
    // Forçar o console a usar a codificação UTF-8
    system("chcp 65001");
    No* raiz = criaAB(10);  // Cria a raiz da árvore

    // Inserindo dados na árvore
    insereAB(raiz, 5);
    insereAB(raiz, 15);
    insereAB(raiz, 3);
    insereAB(raiz, 7);
    insereAB(raiz, 12);
    insereAB(raiz, 18);

    printf("Percurso Pré-Ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf("Percurso In-Ordem: ");
    in_ordem(raiz);
    printf("\n");

    printf("Percurso Pós-Ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Remover um nó (por exemplo, o nó com valor 7)
    printf("Removendo o nó com valor 7...\n");
    remover(raiz, 7);

    printf("Percurso In-Ordem após remoção: ");
    in_ordem(raiz);
    printf("\n");

    return 0;
}
