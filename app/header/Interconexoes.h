#include "Adaptadores.h"
#include "Cidades.h"
<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
=======

/**
* 	Cabecalho do elemento Gerador
* 	
*	nome:
* 		nome do gerador
*
* 	posicaoInicial:
* 		vetor posicaoInicial, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	posicaoInicial:
* 		vetor posicaoInicial, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	chanceFalha:
* 		chance de falha por segundo
*
* 	tempoConcerto:
*		tempo de concerto em caso de falha em segundos
*
*	custoConcerto:
*		custo do concerto em segundos
*
* 	numeroFalha:
* 		total de falhas
*
*	proximo:
*		representa as interconexoes realizadas/apontadas pelos adaptadores
*
* 	adaptador:
*		adaptador utilizado/apontado pela interconexao
*
*	cidade:
*		cidade de destino
*
**/

typedef struct interconexao{
	char *nome;
	int posicaoInical[2];
	int posicaoFinal[2];
	float chanceFalha;
	int tempoConserto;
	int custoConserto;
	int numeroFalha;
	Interconexao *proximo;
	Adaptador *adaptador;
	Cidade *cidade;
	
}Interconexao;


/**
*	Calcula o tamanho da celua de conexao que
* eh passada para a funcao
*
*	@param interconexao;
*		ponteiro para a celula de interconexao
*
*	@return 
*		tamanho da celula de conexao que foi passada
*
**/
float tamanhoConexao(Interconexao *interconexao);


/**
*	Calcula o tamanho total das conexoes 
* da lista que eh passada
*
*	@param interconexao
*		ponteiro para o inicio da lista de celulas de conexao
*
*	@return
*		retorna o tamanho total das conexoes da lista
**/
float tamanhoTotalConexao(Interconexao *interconexao);


/**
*	Calcula o custo total gasto com conserto 
* de todas as celulas de conexao
*
*	@param interconexao
*		ponteiro para o inicio da lista de interconexao
*
*	@return
*		total gasto com conserto de toas as conexoes
*
**/
int totalGastoConserto(Interconexao *interconexao);