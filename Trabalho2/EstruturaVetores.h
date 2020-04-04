#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define PrincipalVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11

struct EstPrincipal{

	int *auxiliar; // VAI APONTAR PARA A ESTRUTURA AUXILIAR
	int tamanho; // TAMANHO DA ESTRUTURA AUXILIAR
	int contador; // ELE VAI CONTAR A QUANTIDADE DE ELEMENTOS no VETOR
};

typedef struct EstPrincipal EstPrincipal;

// Lista Encadeada
struct principal{

	int conteudo;
	struct principal *proximo;
};

typedef struct principal Principal;

int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int PrincipalvoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
Principal* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(Principal* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(Principal** inicio);

void inicializar();
void finalizar();
void dobrar(int *x);
