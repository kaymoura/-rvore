# Árvore Binária - Implementação em C

Este repositório contém a implementação de uma Árvore Binária em C com operações como inserção, remoção e percursos (Pré-Ordem, In-Ordem e Pós-Ordem). A árvore é implementada com uma estrutura de nós, onde cada nó possui um valor (`info`), um ponteiro para o filho à esquerda (`esq`), um ponteiro para o filho à direita (`dir`) e um ponteiro para o pai (`pai`).

## Funcionalidades

- **Inserção de elementos** na árvore binária.
- **Remoção de elementos** da árvore binária, incluindo a reorganização após remoção.
- **Percursos da árvore**:
  - **Pré-Ordem**: Visita o nó, depois o filho à esquerda e, por fim, o filho à direita.
  - **In-Ordem**: Visita o filho à esquerda, depois o nó e, por fim, o filho à direita.
  - **Pós-Ordem**: Visita o filho à esquerda, depois o filho à direita e, por fim, o nó.
  
## Como Usar

### Pré-requisitos

Para rodar este código, você precisa de um compilador de C instalado, como o **GCC** ou o **MinGW** (para Windows). O código foi testado no **Code::Blocks**, mas deve funcionar em qualquer ambiente que suporte compilação C(Exemplo: [https://www.onlinegdb.com/online_c_compiler](https://www.onlinegdb.com/online_c_compiler) ).

### Compilando o código

1. Clone o repositório para o seu ambiente local:

   ```bash
   git clone https://github.com/seu-usuario/arquivo-arvore-binaria.git
