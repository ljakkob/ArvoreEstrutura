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

/*Rotina que faz a inserção na árvore binária de busca
O Parâmetro dado recebe um ponteiro para string
A função não retorna valor nem referência
*/
void inserir()
{
    struct no *alocar; //Ponteiro para fazer alocação

    alocar = (struct no *) malloc(sizeof(struct no)); //Faz alocação na memória

    if (!alocar)   //Se não for possível a alocação, sai do programa
    {
        printf("Falta de memória");
    }

    if (!raiz)   //Esse é o nó DEUS. O alfa e o ômega, o princípio e o fim. O criador de todas as coisas! Javé, Jeová, Alah.
    {
        raiz = alocar;
        raiz->Nome = 0;
        raiz->Sexo = 1;
        raiz->Pai = NULL;
        raiz->Mae = NULL;
        raiz->Filho1 = NULL;
        raiz->Filho2 = NULL;
        raiz->EstCiv = 0;

    }

    else //se não...

    {
        //ponteiros para busca
        struct no *ponteiro;
        struct no *ponteiroAnterior;
        ponteiro = raiz; //ponteiro inicia na raiz
        ponteiroAnterior = NULL; //anterior inicial em NULL

        while (ponteiro)   //Faz a busca do lugar ao qual deve ser inserido o nó
        {

            ponteiroAnterior = ponteiro;



            if (ponteiro->Sexo > 0)
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
            alocar->Sexo = 0;
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
            alocar->Sexo = 1;
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


/*Faz a caminhada em ordem recursiva*/
void caminharEmOrdem(struct no *ponteiro)
{
    if (ponteiro)
    {
        caminharEmOrdem(ponteiro->Filho1);
        if(ponteiro->Nome != 0 && ponteiro->Pai != NULL && ponteiro->Pai->Nome == 0)
        {
            printf("\nNome:%d Sexo: %d Nome do Pai: DEUS\n", ponteiro->Nome, ponteiro->Sexo);
        }
        else if(ponteiro->Nome != 0 && ponteiro->Pai != NULL)
        {
            printf("\nNome: %d Sexo: %d Nome do Pai: %d\n", ponteiro->Nome, ponteiro->Sexo, ponteiro->Pai->Nome);
        }
        if(ponteiro->Nome != 0 && ponteiro->Mae != NULL)
        {
            printf("\nNome: %d Sexo: %d Nome da Mãe: %d\n", ponteiro->Nome, ponteiro->Sexo, ponteiro->Mae->Nome);
        }
        caminharEmOrdem(ponteiro->Filho2);

    }
}


/*Rotina principal
com algumas inserções, um caminhamento e uma busca no final
*/

int main()
{
    inserir();
    inserir();
    inserir();
    inserir();
    inserir();
    inserir();
    inserir();
    //buscar();
    inserir();
    inserir();
    inserir();
    //casar(raiz);
    caminharEmOrdem(raiz);
    printf("\nInserir para buscar: ");
    //printf("%d", buscar(dado));

    getchar();
}