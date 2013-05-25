typedef struct node *link;
struct node {
    int item;
    link next;
};
typedef link Node;

void initNodes(int);         /* Inicia lista     */
Node newNode(int);           /* Cria nova célula */
void freeNode(Node);         /* Libera célula */
void insertNode(Node,Node);  /* Insere a célula do 2º argumento 
                                depois da cálula do 1º argumento */
Node deleteNext(Node);       /* Deleta o próximo após este */
Node Next(Node);             /* Encapsula o conteito dos ponteiros 
                                de C, sendo que esta função devolve
                                a próxima célula */
int Item(Node);              /* Devolve o valos do nódulo (novamente
                                encapsulando o conceito de ponteiro) */
