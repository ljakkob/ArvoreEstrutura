#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

struct no
{

    struct no *Mae; //Ponteiro pra struct feminina que originou o nó filho
    struct no *Pai; //Ponteiro pra struct masculina que originou o nó filho
    int Nome; //Nome do ponteiro
    int EstCiv; //Ponteiro que informa o estado civil do nó. 1 = Casado; 0 = Solteiro
    int Sexo; //Ponteiro que informa o sexo do nó
    struct no *CasadoCom; //Ponteiro pra struct do cônjuge
    struct no *Filho1; //Ponteiro para o filho
    struct no *Filho2; //Ponteiro para o filho
};

int cont=1; //Contador que dá nome aos nós
struct no *raiz; //Ponteiro da raiz
struct no *masc;
struct no *fem;


int inserir()
{
    struct no *alocar; //Ponteiro para fazer alocação
    int sexo,nome;
    printf("Escreva o sexo (0) Para Feminino (1) Masculino\n");
    scanf("%d", &sexo);
    if(sexo > 1){
    sexo = 1;
    }

    alocar = (struct no *) malloc(sizeof(struct no)); //Faz alocação na memória

    if (!alocar)   //Se não for possível a alocação, sai do programa
    {
        printf("Falta de memória");
    }

    if (!raiz)   //Criando a raiz

    {
        raiz = alocar;
        raiz->Nome = 0;
        raiz->Sexo = sexo;
        raiz->EstCiv = 1;
        //raiz->CasadoCom = alocar;
        raiz->Pai = NULL;
        raiz->Mae = NULL;
        raiz->Filho1 = NULL;
        raiz->Filho2 = NULL;
        return 0;

    }

    else //se não...

    {
        //ponteiros para busca
        struct no *ponteiro;
        struct no *ponteiroAnterior;
        ponteiro = raiz; //ponteiro inicia na raiz
        ponteiroAnterior = NULL; //anterior inicial em NULL

printf("Escreva o nome\n");
    scanf("%d", &nome);

        while (ponteiro)   //Faz a busca do lugar ao qual deve ser inserido o nó
        {

            ponteiroAnterior = ponteiro;



            if (ponteiroAnterior->Nome > cont)
            {
                ponteiro = ponteiro->Filho2;
            }
            else
            {
                ponteiro = ponteiro->Filho1;
            }
        }
        if  (ponteiroAnterior->Filho1 != NULL)
        {
            alocar->Nome = cont++;
            alocar->CasadoCom = NULL;
            alocar->Filho1 = NULL;
            alocar->Filho2 = NULL;
            alocar->Sexo = sexo;
            alocar->EstCiv = 0;
            ponteiroAnterior->Filho2 = alocar;

            if(ponteiroAnterior->Sexo == 0)
            {
                alocar->Mae = ponteiroAnterior;
                alocar->Pai = ponteiroAnterior->CasadoCom;
            }
            else
            {
                alocar->Pai = ponteiroAnterior;
                alocar->Mae = ponteiroAnterior->CasadoCom;
            }
            //atribui o endereço de alocação ao ponteiro da direita do nó anterior
        }
        else
        {
            alocar->Nome = cont++; //Copia o dado para o novo nó alocado
            alocar->CasadoCom = NULL;
            alocar->Filho1 = NULL;
            alocar->Filho2 = NULL;
            alocar->Sexo = sexo;
            alocar->EstCiv = 0;
            ponteiroAnterior->Filho1 = alocar;

            if(ponteiroAnterior->Sexo == 0)
            {
                alocar->Mae = ponteiroAnterior;
                alocar->Pai = ponteiroAnterior->CasadoCom;
            }
            else
            {
                alocar->Pai = ponteiroAnterior;
                alocar->Mae = ponteiroAnterior->CasadoCom;
            }
            //atribui o endereço de alocação ao ponteiro da esquerda do nó anterior
        }
    }
}


struct no * buscar(int k) {

      struct no *ponteiro;

      ponteiro = raiz;

      while (ponteiro) {

      if (ponteiro->Nome == k){
       if(ponteiro->Sexo == 1){
        masc = ponteiro;
       }
       else{
       fem = ponteiro;
       }
      } //Faz a comparação de strings
            //return ponteiro; //Retorna ponteiro se o encontrar

      if (ponteiro->Nome > k)
            ponteiro = ponteiro->Filho2;

      else
            ponteiro = ponteiro->Filho1;

      }

      return NULL; //Retorna o ponteiro nulo
}


/*Faz a caminhada em ordem recursiva*/
void caminharEmOrdem(struct no *ponteiro)
{
    if (ponteiro)
    {
        caminharEmOrdem(ponteiro->Filho2);
        printf("Nome: %d  Sexo: %d  ", ponteiro->Nome, ponteiro->Sexo);
        if(ponteiro->Mae != NULL)
        {
            printf("Nome da Mae: %d  ", ponteiro->Mae->Nome);
        }
        if(ponteiro->Pai != NULL)
        {
            printf("Nome do Pai: %d  ", ponteiro->Pai->Nome);
        }
        if(ponteiro->CasadoCom != NULL)
        {
            printf("Casado com: %d  ", ponteiro->CasadoCom->Nome);
        }
        printf("\n\n");
        caminharEmOrdem(ponteiro->Filho1);

    }
}


/*Rotina principal
com algumas inserções, um caminhamento e uma busca no final
*/

int main()
{
  int op=1, k;
    while(op)
    {
        printf("=======================PROJETO ARVORE GENEALOGICA=======================\n\n");
        printf("1-Insere pessoa\n2-Casar\n3-Encontrar Parente\n");
        scanf("%d", &op);
        if(op == 1)
        {
                inserir();
                   }
        if(op == 2)
        {
            printf("Informe o nome do noivo\n");
            scanf("%d", &k);
            buscar(k);
            printf("Informe o nome da noiva\n");
            scanf("%d", &k);
            buscar(k);
            if(masc == NULL || fem == NULL)
            {
                printf("Erro durante a busca!\n");
            }
            else
            {
                printf("masc: %p %d\n", masc, masc->Nome);
                printf("fem: %p %d\n", fem, fem->Nome);
                masc->CasadoCom = fem;
                fem->CasadoCom = masc;

                masc->EstCiv = 1;
                fem->EstCiv = 1;

            }
masc = NULL;
                fem = NULL;
        }
        //printf("%d", masc->Nome);
        //casar();
        if(op == 3)
        {
            caminharEmOrdem(raiz);
        }
    }
    //printf("%d", buscar(dado));
}
