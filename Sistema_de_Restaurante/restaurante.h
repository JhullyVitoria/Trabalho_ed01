#define MAX 50

//struct do produto do cardapio
typedef struct{
	int id;
	char nome[50];
	float preco;	
}Item;

struct pd{
    char nome_cliente[MAX];
    int codigo;
    float valor;
    int qtd;
    float total;
};
typedef struct pd pedido;

struct fila{
    struct pd elemento[MAX];
    int Ini;
    int Fim; 
    int n_elem;
};
typedef struct fila *Fila;

int ler(char l[]);
int imprimemenu(char l[]);

Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);

int insere_fim(Fila f,struct pd elem);
int remove_ini(Fila f,struct pd *elem);

int apaga_fila(Fila *f);
Fila esvazia_fila(Fila f);
int tam_fila(Fila f);
void mostra_fila(struct pd pedido);