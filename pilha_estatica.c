#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO_PILHA 5

typedef struct
{
    float pilha[TAMANHO_PILHA];
    int totalElementos;
} PILHA;

PILHA *CriarPilha()
{
    int i = 0;

    PILHA *pPilha =  (PILHA *) malloc(sizeof(PILHA));

    pPilha->totalElementos = 0;
    for(i = 0; i < TAMANHO_PILHA; i++)
        pPilha->pilha[i] = -1;

    return pPilha;
}

float Empilhar(PILHA *pPilha, float novoElemento)
{
    pPilha->totalElementos++;
    pPilha->pilha[pPilha->totalElementos - 1] = novoElemento;

    return pPilha->totalElementos;
}

float Desempilhar(PILHA *pPilha)
{
    if(pPilha->totalElementos <= 0)
        return -1;
    else
    {
        float elementoRetirado = pPilha->pilha[pPilha->totalElementos - 1];
        pPilha->pilha[pPilha->totalElementos - 1] = -1;
        pPilha->totalElementos--;

        return elementoRetirado;
    }
}

int TotalElementos(PILHA *pPilha)
{
	return pPilha->TotalElementos;
} 

void Listar(PILHA *pPilha)
{
    int i = 0;
    printf("\n\n");

    if(pPilha->totalElementos <= 0)
        printf("\n PILHA VAZIA");
    else
        for(i = 0; i < pPilha->totalElementos; i++)
        printf("[%d] = %.2f\n", i, pPilha->pilha[i]);

    printf("\n\n");
}

void Pause()
{
    printf("\nTecle <ENTER> para continuar...\n");
    getchar();
}

void LimparBuffer(void)
{
  while ((getchar() != '\n') && (!EOF));
}

void LimparTela()
{
  printf("\033[2J");
}

int main()
{
    PILHA *pilha;
    pilha = CriarPilha();

    printf("\nEMPILHAR");

    Empilhar(pilha, 1);
    Empilhar(pilha, 2);
    Empilhar(pilha, 3);
    Empilhar(pilha, 4);
    Empilhar(pilha, 5);


    Listar(pilha);

    printf("\DESEMPILHAR");

    Desempilhar(pilha);
    Desempilhar(pilha);
    Desempilhar(pilha);

    Listar(pilha);

     return 0;
}
