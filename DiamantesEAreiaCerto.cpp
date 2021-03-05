#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stdio.h>  
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;


int main(void) {
	/*
	n = quantidade de casos de teste
	simb = simbolos que serão inseridas na pilha
	pilha = estrutura pilha
	*/
	
	int n, cont, aux, i;
	char simb;
	string comp;

	cin>>n;
	//int resp[n];
	
	for(i=0; i<n; i++){
		fflush(stdin);
		cont=0;
		stack<char>pilha;
		cin >> comp;
			for(aux=0; aux<comp.length();aux++){ //lenght é o problema
				simb = comp[aux];
				if(simb == '<'){
					pilha.push(simb);
				}
				if((simb == '>') && (!pilha.empty())){
					pilha.pop();
					cont++;
				}
			}
		cout<<cont<<endl;	
		//resp[i] = cont;
	}
	return 0;
}
