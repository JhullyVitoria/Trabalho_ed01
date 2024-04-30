#define  max  12
struct choc{
   char nome[max];
};
typedef struct choc Choc;

struct pilha{
    struct choc elementos[max];
    int topo;   // posicao onde está o topo da pilha
};

typedef struct pilha Pilha;

void criar(Pilha *p);
void destruir(Pilha *p);
int vazia(Pilha p);
int cheia(Pilha p);
int empilhar(Pilha *p, struct choc X);
int desempilhar(Pilha *p, struct choc *X);
//void empilhar_chocolate(char p[]);
void empilhar_chocolate(char p[], int codigo_pedido);