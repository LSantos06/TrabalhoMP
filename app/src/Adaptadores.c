#include "../header/Adaptadores.h"
#include <assert.h>

/** -----------------------Funcoes Basicas---------------------------- */

/**
*	Funcao: criaListaAdaptador
*
*	AssertivaSaida:
*		NULL;
**/
Adaptador* criaListaAdaptador(){
	return NULL;
}

/**
*	Funcao: adaptadorVazio
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO;
**/
Vazio adaptadorVazio(Adaptador *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIO;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIO;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereAdaptador
*
*	AssertivaEntrada:
*		registro != NULL;
**/
Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo){
	assert(registro != NULL);

	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador)); //!< Alocacao de um novo adaptador
	char *numChar = (char*) malloc (strlen(registro)*sizeof(char)); //!< Alocacao de um vetor do tamanho do registro
	int i,j=0,k=2; //!< Variaveis de auxilio

	for(i=2;registro[i]!=' ';i++);
	//! AE: a posicao corrente do registro possui um caracter relevante

	//! Comentarios de argumentacao
		/**
		*	Comecando de registro[2], enquanto registro[i] for um caracter irrelevante,
		* soma-se 1 a variavel de auxilio i
		**/

	//! AS: a posicao corrente do registro possui um caracter irrelevante

	//! Asseriva estrutural: o nome do novo adaptador possui tamanho i-1
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<=2;i++){
	//! AE: o valor da variavel auxiliar j deve ser menor ou igual ao numero total de atributos lidos do adaptador

		if(registro[i] == ' '||registro[i] == '\0'){
		//! AE: a posicao corrente do registro possui um caracter irrelevante, ou um caracter finalizador

			if(j == 0){
			//! AE: o valor de j eh igual a 0

				//! Comentarios de argumentacao
					/**
					*	A (posicao corrente-k) recebe um caracter finalizador
					**/
				novo->nome[i-k] = '\0';
			}
			//! AS: o valor de j eh maior que 0

			else{
			//! AE: o valor de j eh maior que 0

				//! Comentarios de argumentacao
					/**
					*	A (posicao corrente-k) do vetor numChar recebe um caracter finalizador
					**/
				numChar[i-k] = '\0';

				//! Comentarios de argumentacao
					/**
					*	De acordo com o valor da variavel auxiliar j, armazena-se o vetor numChar
					* no seu respectivo atributo lido
					**/
				if(j == 1)
					novo->posicao[0] = atoi(numChar);
				else if(j == 2)
					novo->posicao[1] = atoi(numChar);
			}
			//! AS: o valor de j eh maior que 4

			k = i+1;
			j++;
		}
		//! AS: a posicao corrente do registro possui um caracter relevante

		else{
		//! AE: a posicao corrente do registro possui um caracter relevante

			//! Comentarios de argumentacao
				/**
				*	Se o valor da variavel de auxilio j for 0
				*	Entao
				*		armazena-se a posicao corrente do registro na
				*	 (posicao corrente-k) do nome do adaptador
				*	Senao
				*		armazena-se a posicao corrente do registro na
				*	 (posicao corrente-k) do vetor numChar
				*	FimSe
				**/
			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numChar[i-k] = registro[i];
		}
		//! AS: a posicao corrente do registro possui um caracter irrelevante, ou um caracter finalizador
	}
	//! AS: o valor da variavel auxiliar j ultrapassou o numero total de atributos lidos da adaptador

	//! Comentarios de argumentacao
		/**
		*	Os atributos nao lidos do adaptador inserido recebem o valor nulo, e o proximo adaptador
		* da lista que contem o novo adaptador inserido na cabeca recebe a lista de adaptadores atual
		**/
	novo->recursoRecebido = 0;
	novo->saidas = NULL;
	novo->entradas = NULL;
	novo->quantidadeSaidas = 0;


	novo->proximo = listaAlvo;
	listaAlvo = novo;

	return listaAlvo;
}

/**
*	Funcao: imprimeListaAdaptador
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*
**/
void imprimeListaAdaptador(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Imprime os atributos do adaptador corrente
		**/
		printf("nome: %s pos_x: %d pos_y: %d recurso recebido%d quantidade de saidas%d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoRecebido
				,aux->quantidadeSaidas);
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: liberaListaAdaptador
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*
*	AssertivaSaida:
*		adaptadorVazio(listaAlvo) == VAZIO;
*
**/
void liberaListaAdaptador(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux1 = NULL;
	Adaptador *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Adaptador corrente
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(adaptadorVazio(aux1) == VAZIO);
}

/** -----------------------Funcoes de Calculo---------------------------- */

/**
*
*	Funcao: defineDistribuicao
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*		para cada adaptador da lista: adaptador->saidas[i] != null;
**/
void defineDistribuicao(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux;
	Interconexao *conexao; //!< conexoes do adaptador

	int i, somatorio = 0, recursoTransportado;

	//! Assertiva estrutural: aux é a lista nao-nula de adaptadores
	aux = listaAlvo;

	while(aux != NULL){
	//! AE: aux nao chegou ao fim da lista de adaptadores

		if(aux->saidas == NULL){
		//! AE: o adaptador nao possui interconexoes
			return;
		}

		if(aux->peso == NULL){
		//! AE: o adaptador nao possui interconexoes
		//! Comentarios de argumentacao
			/**
			*	Alocacao do vetor de pesos de acordo com a quantidade de saidas que
			* o adaptador possui
			**/
			aux->peso = (int *) malloc(aux->quantidadeSaidas * sizeof(int));
		}

		for(i=0;i<aux->quantidadeSaidas;i++){
		//! AE: o numero total de saidas do adaptador nao foi alcancado pela variavel auxiliar i

			if(aux->saidas[i]->tagFalha == SEM_FALHA){
			//! AE: as interconexoes realizadas pelo adaptador nao possuem falhas
				//! Assertiva estrutural: somatorio contem a soma das capacidades maximas de cada interconexao realizada pelo adaptador
				somatorio += aux->saidas[i]->capacidadeMaxima;
			}
			//! AS: alguma das interconexoes realizadas pelo adaptador possui falha

		}
		//! AS: a quantidade total de saidas foi obtida por meio da variavel auxiliar i

		for (i=0;i<aux->quantidadeSaidas;++i){
		//! AE: o numero total de saidas do adaptador nao foi alcancado pela variavel auxiliar i

			//! Assertiva estrutural: conexao eh a lista de interconexoes do adaptador
			conexao = aux->saidas[i];

			if(conexao->tagFalha == SEM_FALHA){
			//! AE: a interconexao corrente nao possui falha

				//! Assertiva estrutural: recursoTransportado é a quantidade de recurso que cada conexao vai transportar no turno
				recursoTransportado = (conexao->capacidadeMaxima * aux->recursoRecebido) / somatorio;

				/**
				*
				*	if(recursoTransportado <= conexao->capacidadeMaxima){
				*		conexao->recursoTransportado = recursoTransportado;
				*	}else{
				*		conexao->recursoTransportado = conexao->capacidadeMaxima;
				*	}
				*
				**/
				conexao->recursoTransportado = (recursoTransportado <= conexao->capacidadeMaxima)
											 ?  recursoTransportado : conexao->capacidadeMaxima;
			}
			//! AS: a interconexao corrente possui falha

		}
		//! AS: a quantidade total de saidas foi obtida por meio da variavel auxiliar i

		aux = aux->proximo;
	}
	//! AS: a lista de adaptadores chegou ao fim
}
