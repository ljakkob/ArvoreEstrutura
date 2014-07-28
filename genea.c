#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

struct no
{

    struct no *Mae; //Ponteiro pra struct feminina que originou o filho
    struct no *Pai; //Ponteiro pra struct masculina que originou o filho
    int Nome; //Nome do ponteiro
    int EstCiv; //Ponteiro que informa o estado civil 1 = Casado; 0 = Solteiro
    int Sexo; //Ponteiro que informa o sexo 
    struct no *CasadoCom; //Ponteiro pra struct do conjuge
    struct no *Filho1; //Ponteiro para o filho
    struct no *Filho2; //Ponteiro para o filho
};

int cont=1; //Contador que dá nome aos nós
struct no *raiz; //Ponteiro da raiz
struct no *masc;
struct no *fem;

/*Rotina que faz a insersão na Arvore  de busca
O Parametro dado recebe um ponteiro para string
A funcao nao retorna valor nem referencia
*/
void inserir()
{
    struct no *alocar; //Ponteiro para fazer alocacao

    alocar = (struct no *) malloc(sizeof(struct no)); //Faz alocacao na memoria

    if (!alocar)   //Se nao for possível a alocação, sai do programa
    {
        printf("Falta de memoria");
    }

    if (!raiz)   //Criação da raiz.
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

    else 

    {
        //ponteiros para busca
        struct no *ponteiro;
        struct no *ponteiroAnterior;
        ponteiro = raiz; //ponteiro inicia na raiz
        ponteiroAnterior = NULL; //anterior inicial em NULL

        while (ponteiro)   //Faz a busca do lugar ao qual deve ser inserido o nó
        {

            ponteiroAnterior = ponteiro;



            if (ponteiro->Nome > 0)
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
            //atribui o endereco de alocacaoo ao ponteiro da esquerda do nó anterior
        }
    }
}

buscar()
{
    struct no *ponteiro;
    struct no *ponteiroAnterior;
    ponteiro = raiz; //ponteiro inicia na raiz
    ponteiroAnterior = NULL; //anterior inicial em NULL


    while (ponteiro)   //Faz a busca do lugar ao qual deve ser inserido o nó
    {

        ponteiroAnterior = ponteiro;



        if (ponteiro->Nome > 0)
        {
            ponteiro = ponteiro->Filho2;
            if( ponteiroAnterior->Sexo == 0)
            {
               if ( ponteiroAnterior->EstCiv != 1 ){
                fem = ponteiroAnterior;
               }
            }
        }
        else
        {
            ponteiro = ponteiro->Filho1;
            if( ponteiroAnterior->Sexo == 1)
            {
                 if ( ponteiroAnterior->EstCiv != 1 ){
                masc = ponteiroAnterior;
               }
            }

        }

    }
}


/*Faz a caminhada em ordem recursiva*/
void caminharEmOrdem(struct no *ponteiro)
{
    if (ponteiro)
    {
        caminharEmOrdem(ponteiro->Filho1);
        printf("Nome: %d  ", ponteiro->Nome);
        if(ponteiro->Mae != NULL){
        printf("Nome da Mae: %d  ", ponteiro->Mae->Nome);}
        if(ponteiro->Pai != NULL){
        printf("Nome do Pai: %d  ", ponteiro->Pai->Nome);}
        if(ponteiro->CasadoCom != NULL){
        printf("Casado com: %d  ", ponteiro->CasadoCom->Nome);}
        printf("\n\n");
        caminharEmOrdem(ponteiro->Filho2);

    }
}

casar()
{
    buscar();
    fem->EstCiv=1;
    masc->EstCiv=1;

    fem->CasadoCom = masc;
    masc->CasadoCom = fem;
}



/*Rotina principal
com algumas insercoes, um caminhamento e uma busca no final
*/

int main()
{
    inserir();
    inserir();
    inserir();
    inserir();
    casar();
    inserir();
    inserir();
    casar();
    inserir();
    caminharEmOrdem(raiz);
    //printf("%d", buscar(dado));

    getchar();
}
