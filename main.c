/*
  Alunos: Jhully Vitória Nunes Leite. Matrícula: 12011BCC058
          Welligton dos Reis Ferreira. Matrícula: 12111BSI286 

  O objetivo do trabalho é criar um programa de sistema de restaurante, onde possui
o cardápio do restaurante, um brinde pra quem realiza o pedido nele, e uma comanda, detalhando nome, codigo e vaor totaldo produto. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "restaurante.h"

int main()
{	
	char menu[] = {"Menu.txt"};
	int temp;

  Fila f;
  f = cria_fila();
  struct pd pedido;

  FILE *choc = fopen("Chocolates.txt", "r");
  
  char ch [] = {"Chocolates.txt"};
  Pilha aux, pi;
  criar(&pi);
  criar(&aux);
  
  do
	{
    printf("============\n");
		printf("Restaurante\n");
    printf("============\n");
		printf("\t1 - Olhar menu\n");
    printf("\t2 - Realisar um pedido\n");
    printf("\t3 - Olhar comanda\n");
    printf("\t4 - Ver tamanho da fila\n");
    printf("\t5 - Esvaziar fila\n");
    printf("\t6 - Encerrar o programa\n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &temp);

    if(temp == 6){printf("Programa encerrado.\n");
      break;}
    
		switch(temp)
	  {
		  case 1://ler menu
            printf("===================================================\n");
		        printf("\t               MENU                  \n");
            printf("===================================================\n");
		        printf(" ID                ITEM                     PRECO\n\n");
		
		        ler(menu);
		        imprimemenu(menu);
		
		        printf("\n\t************************************\n\n");
		        printf("\n");
		   break;

      case 2:

            printf("Digite o nome do cliente: ");
			      scanf("%s",pedido.nome_cliente);
            setbuf(stdin, NULL);

				      printf("\nDigite o codigo do pedido: ");
				      scanf("%d", &pedido.codigo);

              if (pedido.codigo < 1 || pedido.codigo > 12)
              {
                 printf("Tente uma opcao valida. (1 a 12)");
                 return 2;
              }
      
              if (pedido.codigo == 1)
              {
                pedido.valor = 30.00;
                printf("Quantidade: ");
                scanf("%d", &pedido.qtd);
                pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 2)
              {
                pedido.valor = 25;
                printf("Quantidade: ");
                scanf("%d", &pedido.qtd);
                pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
                 
              if (pedido.codigo == 3)
              {
                pedido.valor = 32;
                printf("Quantidade: ");
                scanf("%d", &pedido.qtd);
                pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido); 
              }
              
              if (pedido.codigo == 4)
              { 
                 pedido.valor = 28;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 5)
              {
                 pedido.valor = 24;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 6)
              {
                 pedido.valor = 50;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 7)
              {
                 pedido.valor = 75;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 8)
              {
                 pedido.valor = 45.90;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                   insere_fim(f, pedido);
              }
              if (pedido.codigo == 9)
              {
                 pedido.valor = 43;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 10)
              {
                 pedido.valor = 38;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 11)
              {
                 pedido.valor = 12;              
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
              if (pedido.codigo == 12)
              {
                 pedido.valor = 8;
                 printf("Quantidade: ");
                 scanf("%d", &pedido.qtd);
                 pedido.total = (pedido.valor*pedido.qtd);
                  insere_fim(f, pedido);
              }
       break;

      case 3:
          if(fila_vazia(f) == 1)
            printf("Vazio.\n");
          while((fila_vazia(f)) != 1)
            {
              remove_ini(f, &pedido);
              printf("\tNome do cliente eh: %s \n", pedido.nome_cliente);
              printf("\tCodigo do pedido: %d   \n", pedido.codigo);
              printf("\tQuantidade de pedidos: %d\n", pedido.qtd);
              printf("\tValor total: %.2f\n", pedido.total);
              empilhar_chocolate(ch);
            }
      break;

      case 4:
        printf("%d\n", tam_fila(f));
        break;

      case 5:
        if(esvazia_fila(f) == 0)
          printf("Nao foi possivel concluir essa operacao.\n");
        else
         printf("Operacao concluida.\n");
       break;
      
      default: 
            printf("Digite os numeros de 1 a 6\n");
       break;
    }
  }while(temp>0 || temp<7);

   destruir(&pi);
   destruir(&aux);
   apaga_fila(&f);
   fclose(choc);

}
