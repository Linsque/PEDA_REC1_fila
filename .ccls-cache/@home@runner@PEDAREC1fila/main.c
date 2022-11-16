// Rafael Bonfim Zacco

/*
Esta Recuperação permite que a média dos trabalhos 1, 2, 3, 4, 5, 6, 7, 8 chegue a, no máximo 7,0.  

Para obter estes pontos você precisará criar as estruturas de dados especificadas nos itens a e b, sem esquecer que uma estrutura de dados é composta de uma representação em  memória e, no mínimo três funções (ou métodos) para a sua manipulação. Sendo assim, todas as estruturas de dados terão, um método para inclusão, um método para exclusão e um método para busca.  

a) Usando, C, C++, Python ou Java, crie uma estrutura de dados chamada minhaNovaFila que deverá usar como representação em memória uma lista linkada. Para testar esta estrutura você  precisará  criar  uma  fila  com  100  registros  compostos  de  uma  string com  até  100 caracteres e um valor numérico do conjunto dos números reais. Para gerar os strings e os valores  números  você  deverá  usar  um  gerador  de  números  randômicos  baseado  no Mersenne Twister. 
 
Durante a criação dos registros você deverá escolher, aleatóriamente dois destes registros para testar a função de busca.
 
Uma vez que a lista tenha sido criada você deve contar o tempo necessário para tirar 20% dos  registros desta fila e o  tempo  necessário  para encontrar a posição na fila onde estão dois  dos  registros  criados.  Neste  exercício,  o  tempo  gasto  em  todas  as  operações  com  a estrutura de dados deverá ser registrado. 

A saída esperada será feita por meio de um arquivo onde teremos a fila original impressa na  horizontal  com  comprimento  inferior  a  5 registros  por  linha,  seguida da  fila  depois  da exclusão de 20% dos seus registros, também na horizontal.  

As últimas linhas do arquivo de saída serão reservadas para o registro dos tempos médios utilizados para cada uma das operações da estrutura de dados (criação, inclusão, exclusão, nova inclusão) como  estes tempos serão muito pequenos será necessário  tirar as médias com, no mínimo, 50 repetições.  

b) Usando, C, C++, Python ou Java, crie uma estrutura de dados chamada eitaHeap que deverá usar  como  representação  em  memória  uma  lista  linkada.  Para  testar  esta  estrutura  você precisará criar um heap (min heap) com 100 registros compostos de uma string com até 100 caracteres e um valor numérico do conjunto dos números reais. Para gerar os strings e os valores  números  você  deverá  usar  um  gerador  de  números  randômicos  baseado  no Mersenne Twister.  

Durante a criação dos registros você deverá escolher, aleatoriamente dez destes registros para testar a função de busca. 

Uma vez que a heap tenha sido criada você deve contar o tempo necessário para tirar 16% dos registros deste heap, o tempo necessário para encontrar a posição na fila onde estão os registros escolhidos para teste e o tempo necessário para  inserir 45 registros novos neste heap. Sem dúvida os testes para a localização dos dez registros selecionados para o resgistro dos  tempos  de  localização  deverão  ser  feitos  com  o  heap originalmente  criado,  antes  da exclusão de 16% ou da inclusão de novos registros.

Como a estrutura é muito pequena, todos os tempos deverão ser calculados na forma de média o que implica na repetição dos processos de criação, inserção, remoção, busca e nova inserção, no mínimo 50 vezes.  

A saída esperada será feita por meio de um arquivo onde teremos o heap estruturado em formato de árvore usando ASCII, seguido do heap com menos 16% dos registros, também estruturado no formato de uma árvore usando ASCII, seguido do heap após a inclusão de novos registros, seguido dos tempos médios de inclusão, exclusão, busca e nova  inclusão identificados cada um em sua própria linha. 
*/

/*
a) fila e lista encadeada (first in, first out)
- criar uma fila com 100 registros (cada registro deve ter até 100 caracteres e um valor numérico)
- buscar, de forma aleatória, dois registros que foram inseridos e suas posições
- retirar 20% dos registros
- buscar, de forma aleatória, dois registros que foram inseridos e suas posições

- saída (em um arquivo):
fila original impressa na horizontal (com menos de 5 registros por linha)
fila após exclusão de 20% dos registros
tempo médio (50 repetições) de todas as operações (inclusão,busca,exclusão,busca)


b) min heap e lista encadeada (árvore crescente)
- criar uma fila com 100 registros (cada registro deve ter até 100 caracteres e um valor numérico)
- buscar, de forma aleatória, dez registros que foram inseridos e suas posições 
- retirar 16% dos registros
- inserir 45 registros novos

-saída (em um arquivo):
heap em formato de árvore (ASCII)
heap sem 16% dos registros
heap após inclusão de 45 registros novos
tempo médio (50 repetições) de todas as operações (inclusão,busca,exclusão,inclusão)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM_STRING 100

typedef struct no{   //valores linkados

  int valor;
  char registro[TAM_STRING];
  struct no *proximo;

} No;

typedef struct lista{  //estrutura de uma lista com atributos necessários para uma fila

  struct lista *tamanho;
  No *inicio;    // head
  No *final;   // tail

} Lista;

void criaLista (Lista *lista){  //método construtor da lista
  lista->tamanho = 0;
  lista->inicio = NULL;
}

void inserir (Lista *lista, int novo_valor, char novo_registro[]){
  
  No *novo = (No*)malloc(sizeof(No));  //alocando na memória um novo nó
  No *aux = (No*)malloc(sizeof(No));  //alocando na memória um nó auxiliar

  if(novo){  //se a alocação ocorreu corretamente...
    novo->valor = novo_valor;
    strcpy(novo->registro,novo_registro);
    novo->proximo = NULL;

    //se for o primeiro:
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    //se não for o primeiro:
    else{
      aux = lista->inicio;

      while(aux->proximo != NULL){
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
    lista->tamanho++;
    lista->final = novo;
  }
  else{  //se não foi possível alocar...
    printf("Não foi possível alocar a memória do novo nó!\n");
  }

}

void remover(Lista *lista){
  
  No *remover = NULL;
  No *aux = NULL;

  if(lista->inicio){  //continua se a lista não for nula
    remover = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(remover);
  }
  else{  //dá erro se a lista for nula
    printf("Não é possível remover um valor da fila pois a mesma não possui nenhum valor!\n");
  }

}

void imprimir (Lista lista){
  
  No *no = lista.inicio;
  
  printf("Valor Numérico [ ");
  while(no->proximo != NULL){
    printf("%d,",no->valor);
    no = no->proximo;
  }
    printf("%d ]\n",no->valor);

  no = lista.inicio;
  printf("Caracteres [ ");
  while(no->proximo != NULL){
    printf("%s ",no->registro);
    no = no->proximo;
  }
  printf("%s ]\n",no->registro);
  
}

int main() {

  srand(time(NULL));
  mt_init();
  
  clock_t timer;
  double soma = 0;
  double media = 0;
  double media_parcial = 0;
  int valor_aleatorio;

  Lista minhaNovaFila;
  criaLista(&minhaNovaFila);

  for (int k=0 ; k<50 ; k++) {
    timer = clock();
    minhaNovaFila.tamanho = 0;
    minhaNovaFila.inicio = NULL;
    minhaNovaFila.final = NULL;

    for (int i=0 ; i<TAM_STRING ; i++) {
      valor_aleatorio = 1 + (abs)((int)mt_random()) % 100;
      
      char caractere_aleatorio[TAM_STRING] = {0};
      for (int j=0 ; j<valor_aleatorio ; j++)
        caractere_aleatorio[j] = 97 + (abs)((int)mt_random() % (122 - 97));
      inserir(&minhaNovaFila, valor_aleatorio, caractere_aleatorio);
    }
    timer = clock() - timer;
    media_parcial = media_parcial + ((double)timer)/CLOCKS_PER_SEC;
    }
  media = media_parcial / 50;

  printf("Lista inicial: (Num. elementos: %d) {", minhaNovaFila.tamanho);
  imprimir(minhaNovaFila);  
  
  return 0;
}