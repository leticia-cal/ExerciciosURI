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
	if (k > pai->chave)
		pai->dir = novo;
	else {
		pai->esq = novo;
	}
	return 0;
}

/*
Executa um percurso pre-ordem 
*/
void preOrdemNo(no_t *raiz) {
	if (raiz == NULL)
		return;
	std::cout <<" "<<raiz->chave;
	preOrdemNo(raiz->esq);
	preOrdemNo(raiz->dir);
}

void preOrdem(abb_t abb) {
	preOrdemNo(abb.raiz);
	std::cout << std::endl;
}

/*
Executa um percurso em ordem 
*/
void inOrderNo(no_t *temp) {
	if (temp == NULL)
		return;
   else{
      inOrderNo(temp->esq);
      cout<<" "<<temp->chave;          
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
      cout<<" "<<temp->chave;
   }
}

void posOrdem(abb_t abb) {
	posOrdemNo(abb.raiz);
	std::cout << std::endl;
}

int main(void) {
	/*
	c = numero de casos de teste
	n = quantidade de números que deve compor cada árvore
	*/
	
	int valor, c, n;
	abb_t arv;
	no_t *ret;

	cin>>c;
	
	for(int i=0; i<c; i++){
		inicializaABB(&arv);
		cin>>n;
		for(int j=0; j<n; j++){
			cin>>valor;
			insereABB(&arv, valor);
		}
		cout<<"Case "<<i+1<<":"<<endl;
		cout<<"Pre.:";
		preOrdem(arv);
		cout<<"In..:";
		inOrder(arv);
		cout<<"Post:";
		posOrdem(arv);
		cout<<endl;
	}
	return 0;
}
