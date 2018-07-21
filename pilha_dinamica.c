#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
	float valor;
	int totalElementos;
	struct pilha *proximo;
	struct pilha *topo;
} PILHA;

PILHA *IniciarPILHA()
{
	PILHA *pPilha = (PILHA *)malloc(sizeof(PILHA));
	pPilha->proximo = NULL;
	pPilha->topo = NULL;
	pPilha->valor = 0;
	pPilha->totalElementos = 0;

	return pPilha;
}

int PilhaVazia(PILHA *pPilha)
{
	return (pPilha->topo == NULL);
}

int LiberarPilha(PILHA *pPilha)
{
	PILHA *pAux = NULL;
	for (pAux = pPilha->topo; pAux != NULL; pAux = pAux->proximo)
		free(pAux);

	free(pPilha);
}


int TotalElementos(PILHA *pPilha)
{
	return pPilha->totalElementos;
}


void *Empilhar(PILHA *pPilha, float valor)
{
	PILHA *novoElemento = (PILHA *)malloc(sizeof(PILHA));
	novoElemento->valor = valor;
	novoElemento->proximo = pPilha->topo;

	if (PilhaVazia(pPilha))
		pPilha->proximo = novoElemento;

	pPilha->topo = novoElemento;
	pPilha->totalElementos++;
}

void *Desempilhar(PILHA* pPILHA)
{
	PILHA *noTopoRemover = pPILHA->topo;
	pPILHA->topo = noTopoRemover->proximo;
	pPILHA->totalElementos--;
	free(noTopoRemover);
}

void LimparTela()
{
	system("cls");
}

void ImprimirPILHA(PILHA *pPILHA)
{
	LimparTela();

	if (PilhaVazia(pPILHA))
		printf("\n PILHA VAZIA !!! \n\n");
	else
	{
		printf("\n PILHA \n\n");
		PILHA *pAux = NULL;
		for (pAux = pPILHA->topo; pAux != NULL; pAux = pAux->proximo)
			printf(" %f \n", pAux->valor);
	}
}


void ImprimirMenu()
{
	LimparTela();
	printf("\n MENU \n");
	printf(" [1] - EMPILHAR \n");
	printf(" [2] - DEMPILHAR    \n");
	printf(" [3] - IMPRIMIR \n");
	printf(" [4] - TOTAL ELEMTENTOS \n");
	printf(" [5] - SAIR     \n");
	printf("\n\n OPCAO: ");
}

void LimparBuffer()
{
	while (getchar() != '\n');
}

int main()
{
	PILHA *pilha;
	pilha = IniciarPILHA();
	int opcao = 0;

	do
	{
		ImprimirMenu();
		scanf(" %d", &opcao);
		LimparBuffer();

		if (opcao == 1)
		{
			float x = 0;
			printf("\n Entre com o numero: ");
			scanf(" %f", &x);
			LimparBuffer();

			Empilhar(pilha, x);
			printf("\n O %f FOI EMPILHADO !!!", x);
			getchar();
		}
		else if (opcao == 2)
		{
			if (PilhaVazia(pilha))
			{
				printf("\n PILHA VAZIA !!!\n");
				getchar();
			}
			else
			{
				Desempilhar(pilha);
				printf("\n DESEMPILHADO COM SUCESSO...!\n\n");
				getchar();
			}
		}
		else if (opcao == 3)
		{
			ImprimirPILHA(pilha);
			getchar();
		}
		else if (opcao == 4)
		{
			LimparTela();
			printf("\n TOTAL ELEMENTOS: %d", pilha->totalElementos);
			getchar();
		}
	} while (opcao != 5);
	LiberarPilha(pilha);
	return 0;
}