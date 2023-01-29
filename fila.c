#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "restaurante.h"

//função abrir arquivo para leitura
int ler(char l[])   
{		
	FILE *file = fopen(l, "r");
  
	if (file == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return 1;
	}
}

//função para imprimir o menu
int imprimemenu(char l[])  
{
	Item menu;
	ler(l);
  
	FILE *lista_menu = fopen(l, "r");
  
	if(lista_menu)
	{
		while(fscanf(lista_menu, "%d%s%f", &menu.id, menu.nome, &menu.preco) != -1)
			printf(" %d - %s R$%.2f\n", menu.id, menu.nome, menu.preco);		
			fclose(lista_menu);
			return 0;
	}
	else
		printf("\nERRO ao abrir arquivo!\n");
		return 1;
}


// aloca uma instancia, atribui zero ao inicio e 
//ao fim da fila e retorna a fila criada
Fila cria_fila()
{
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->Ini = 0;
        f->Fim = 0;
    }
    return f;
}

//Verifica se o ini da fila é igual ao fim, se for, a lista está vazia. 
//Retorna 1 p/ sucesso e 0 para fracasso
int fila_vazia(Fila f)
{
    if (f->Ini == f->Fim)
       return 1;
    else
       return 0;
}

//verifica se a fila está cheia, caso esteja retora 1 como verdadeiro, else retorna 0
int fila_cheia(Fila f)
{
    if (f->Ini == (f->Fim+1) % MAX)
       return 1;
    else
       return 0;
}

//Verifica se a fila está alocada ou cheia. Em seguida, insere o elemento no fim da fila. E encrementa um no valor do n_elementos da fila.
int insere_fim(Fila f, struct pd elem)
{	
    if (f == NULL || fila_cheia(f) == 1)
       return 0;
  
    f->elemento[f->Fim] = elem;
    f->n_elem = f->Fim +1;

  	if (f->Fim == (MAX-1)) 
        f->Fim = 0;
	 else 
        f->Fim = f->Fim + 1;
    
    return 1;
}

//Verifica se a fila foi alocada e se ela não está vazia. Em seguida, remove o elemento da fila por meio do ini e decrementa o n_elementos.
int remove_ini(Fila f,struct pd *elem)
{ 
    if (f == NULL || fila_vazia(f) == 1)
       return 0;
  
    *elem = f->elemento[f->Ini];
     f->n_elem = f->n_elem -1;
  
    if(f->Ini == (MAX - 1))
      f->Ini = 0;
    else
      f->Ini = f->Ini+1;
    return 1;
}

//Libera a memoria alocada para a fila e atribui NULL para o struct.
int apaga_fila(Fila *f)
{
    if (f == NULL)
       return 0;
    
    free(*f);
    *f = NULL;

    return 1;
}

//Verifica se a fila está alocada ou vazia, caso esteja tudo correto, essa função atribui para o ini, o fim e o n_elem o comeco da struct
Fila esvazia_fila(Fila f)
{
    if (f == NULL || fila_vazia(f) == 1)
        return 0;
  
    f->Ini = 0;
    f->Fim = 0;
    f->n_elem = 0;

    return f;
}

//Retorna o valor do nº de elementos da fila, que indica o tamanho.
int tam_fila(Fila f)
{
    if (f == NULL)
        return 0;

    return f->n_elem;
}

