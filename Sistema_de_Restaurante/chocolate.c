#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"restaurante.h"
#include"pilha.h"

void criar(Pilha *p){
    p->topo = -1;
}

void destruir(Pilha *p){
    p->topo = -1;
}

int vazia(Pilha p){
    if (p.topo == -1) 
      return 1;
    else 
      return 0;
}

int cheia(Pilha p){
    if (p.topo == (max - 1)) 
      return 1;
    else 
      return 0;
}

//Verifica se a pilha está cheia, caso não tiver, ele incrementa o topo, pois o topo = -1 e depois empilha o elemento na pilha. E retorna 1 case dê certo, 0 pra falha.
int empilhar(Pilha *p, struct choc X){
    if (cheia(*p) == 1) 
        return 0;
  
    p->topo = p->topo + 1;
    p->elementos[ p->topo ] = X;
        return 1;
}

//Verifica se a pilha está vazia caso não esteja, essa função decrementa o topo da pilha, e desempilha o último elemento inserido. E retorna 1 case dê certo, 0 pra falha.
int desempilhar(Pilha *p, struct choc *X){
    
    if (vazia(*p) == 1) 
        return 0;
  
    *X = p->elementos[ p->topo ];
    p->topo = p->topo - 1;
    
        return 1;
}

// Essa função vai fazer o processo de empilhar os chocolates por meio do arquivo Chocolate.txt e 
//as funções empilha e desempilha. Para sair o nome correto do chocolate tem a pilha auxiliar.
void empilhar_chocolate(char p[], int codigo_pedido) {
    struct choc elementos;
    Pilha pi;
    Pilha aux;
    criar(&pi);
    criar(&aux);

    FILE *choc = fopen("Chocolates.txt", "r");

    if (choc) {
        while (cheia(pi) == 0) {
            fscanf(choc, " %s", elementos.nome);
            empilhar(&pi, elementos);
        }

        fclose(choc);

        while (vazia(pi) == 0) {
            desempilhar(&pi, &elementos);
            empilhar(&aux, elementos);
        }

        // Selecionar o brinde com base no código do pedido
        if (!vazia(aux)) {
            int indice_brinde = codigo_pedido - 1; // Ajuste para indexação do vetor (código - 1)
            for (int i = 0; i < indice_brinde; i++) {
                desempilhar(&aux, &elementos);
            }
            printf("\tBrinde: %s\n\n", elementos.nome);
        }
    }
}
