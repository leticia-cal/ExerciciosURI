#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stdio.h>  
#include <stdlib.h>

using namespace std;

struct no_t {
	int chave;
	no_t *esq;
	no_t *dir;
};

struct abb_t {
	no_t *raiz;
};

int contador = 0;

/*
Inicializa uma ABB, atribuindo NULL
na raiz
*/
void inicializaABB(abb_t* abb) {
	(abb)->raiz = NULL;
}

/*
Verifica se a ABB est? vazia
*/
bool vaziaABB(abb_t abb) {
	return (abb.raiz) ? false : true;
}

/*
Cria um n? com dada chave
*/
no_t* criaNo(int chave) {
	no_t *novo;
	novo = new no_t;
	novo->chave = chave;
	novo->esq = novo->dir = NULL;
	return novo;
}

/* Busca um valor (int) a partir de um n? raiz */
no_t* buscaNo(no_t* raiz, int k) {
	if (raiz == NULL) 
		return NULL;
	if (raiz->chave == k) {
		return raiz;
	} else if (k > raiz->chave) {
		return buscaNo(raiz->dir, k);
	} else {
		return buscaNo(raiz->esq, k);
	}
}


/*
Insere uma chave na ABB
Retorna:
0: sucesso
-1: chave j? existe
*/
int insereABB(abb_t* abb, int k) {
	no_t *pai, *atual, *novo;
	if (vaziaABB(*abb)) {
		abb->raiz = criaNo(k);
		return 0;
	}
	pai = atual = abb->raiz;
	while (atual != NULL) {
		pai = atual;
		if (atual->chave == k) {
			return -1;
		}else if (k > atual->chave) {
			atual = atual->dir;
		} else if (k < atual->chave) {
			atual = atual->esq;
		}
	}
	novo = criaNo(k);
	contador++;
	if (k > pai->chave)
		pai->dir = novo;
	else {
		pai->esq = novo;
	}
	return 0;
}

/*
Busca uma chave na ABB
Retorna:
ponteiro para o n?: sucesso
NULL: caso chave n?o exista na ABB
*/
no_t* buscaABB(abb_t abb, int k) {
	if (vaziaABB(abb))
		return NULL;
	return buscaNo(abb.raiz, k);
}

/*Remove um nó
no_t* *delete(info: tipo info, arv: *nodo)
        início
                tmp, filho: *nodo;
                se arvore == nulo então
                        retorne erro;
                senão 
                    se (info < arv ->info) // vá a esq.
                         arv->esq <- delete(info, arv->esq);
                         retorne arv;
                    senão 
                        se (info > arv ->info) // vá a dir.
                             arv->dir <- delete(info, arv->dir);
                             retorne arv;
                        senão // encontrei elemento que quero deletar.
                            se (arv->dir ~= nulo E arv->esq ~= nulo)// 2 fil
                                    tmp <- minimo(arv->dir);
                                    arv->info <- tmp->info;
                                    arv->dir <- delete(arv->info, arv->dir);
                                    retorne arv;
                            senão // um filho só
                                    tmp <- arv;
                                    se (arv->dir != nulo) então // um filho à dir.
                                        filho <- arv->dir;
                                        retorne filho;
                                    senão 
                                        se (arv->esq != nulo) então // filho esq.
                                            filho <- arv->esq;
                                            retorne filho;
                                        senão // folha
                                            libere arv;
                                            retorne nulo;
                                        fim se 
                                    fim se
                            fim se
                        fim se 
                    fim se
                fim se
        fim
*/

/*
Executa um percurso pre-ordem 
*/
void preOrdemNo(no_t *raiz) {
	if (raiz == NULL)
		return;
	std::cout << raiz->chave << " ";
	preOrdemNo(raiz->esq);
	preOrdemNo(raiz->dir);
}

void preOrdem(abb_t abb) {
	preOrdemNo(abb.raiz);
	std::cout << std::endl;
}


// Pega o valor maior entre dois
int max(int a, int b) {
   return ((a > b) ? a : b); //retorna "a" se "a>b" for verdadeiro, retorna "b" se "a>b" for falso
}

// ve a altura de uma arvore
int pegaAltura(no_t *raiz) {
   if (raiz == NULL)
         return 0;
         
    int esqda = pegaAltura(raiz->esq);
    int dirta = pegaAltura(raiz->dir);
    	
    return max(esqda, dirta) + 1;
}

void altura(abb_t abb){
	cout<<"Altura da arvore = "<< pegaAltura(abb.raiz)<<endl;
}

/*
Executa um percurso em ordem 
*/
void inOrderNo(no_t *temp) {
	if (temp == NULL)
		return;
   else{
      inOrderNo(temp->esq);
      cout<<temp->chave<<" ";          
      inOrderNo(temp->dir);
   }
}

void inOrder(abb_t abb) {
	inOrderNo(abb.raiz);
	std::cout << std::endl;
}

/*
Executa um percurso pós-ordem 
*/
void posOrdemNo(no_t *temp) {
	if (temp == NULL)
		return;
   else{
      posOrdemNo(temp->esq);          
      posOrdemNo(temp->dir);
      cout<<temp->chave<<" ";
   }
}

void posOrdem(abb_t abb) {
	posOrdemNo(abb.raiz);
	std::cout << std::endl;
}

int tam=0;

void menu(void) {
	cout << "-------------------------\n";
	cout << "Arvore Binaria de Busca\n";
	cout << "-------------------------\n";
	cout << "i <valor>: insere chave <valor>\n";
	cout << "b <valor>: busca chave <valor>\n";
	cout << "r <valor>: remove chave <valor>\n";
	cout << "v        : arvore vazia?\n";
	cout << "a        : altura da arvore\n";
	cout << "p        : percurso pre-ordem\n";
	cout << "n        : percurso in-ordem\n";
	cout << "s        : percurso pos-ordem\n";
	cout << "t        : numero de nos da arvore\n";
	cout << "f        : encerra programa\n";
	cout << "-------------------------\n";
	cout << "<< OPCAO: ";
}
int main(void) {
	char opt;
	int valor;
	abb_t arv;
	no_t *ret;

	inicializaABB(&arv);

	do {
		menu();
		cin >> opt;
		switch(opt) {
			case 'i':
				cin >> valor;
				if (insereABB(&arv, valor) < 0)
					cout << "\033[1;31m Erro:\033[0m valor ja existe!" << endl;
				else 
					cout << "Valor inserido" << endl;
				break;
			case 'b':
				cin >> valor;
				ret = buscaABB(arv, valor);
				if (ret == NULL)
					cout << "Valor nao encontrado\n";
				else 
					printf("Chave na posicao %p\n", ret);
				break;
			case 'v':
				if (vaziaABB(arv))
					cout << "Arvore vazia!\n";
				else
					cout << "Arvore contem elementos!\n";
				break;
			case 'a':
				altura(arv);
				break;
			case 'r':
				break;
			case 'p':
				preOrdem(arv);
				break;
			case 'n':
				inOrder(arv);
				break;
			case 's':
				posOrdem(arv);
				break;
			case 't':
				cout<<"Numero de nos: "<<contador<<endl;
				break;
			case 'f':
				break;
			default:
				cout << "\033[1;31m Erro:\033[0m opcao invalida\n";
		}
	} while (opt != 'f');
	cout << "That's all folks!\n";

	return 0;
}
