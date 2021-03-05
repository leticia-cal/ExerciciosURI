#include<iostream>
 
using namespace std;
/*

n = quantidade de casos teste
m = quantidade de endereços na tabela
c = quantidade de chaves a serem armazenadas

*/
int main(){
	int n; //quantidade de casos teste
	cin>>n;
	while(n--){	
		int m; //m = quantidade de endereços da tabela
		int c; //c = quantidade de chaves a serem armazenadas
		cin>>m>>c;
		int vet[c]; //vetor p/ armazenar as chaves
		for(int i=0; i<c; i++){
			cin>>vet[i]; //coleta as chaves
		}
		for(int j=0; j<m; j++){ //exibe as posições da tabela hash
			cout<<j<<" -> ";
			for(int k=0; k<c; k++){
				if(vet[k]%m == j){ //faz a comparação do resto com a posição da tabela
					cout<<vet[k]<<" -> ";
				}
			}
			cout<<"\\";
			if((n != 0) || (j < m-1)){
				cout<<endl;
			}
		}
		//if(n != 0){
			cout<<endl;
		//}
	}
}
 
/*
int main()
{
    int n; //quantidade de casos teste
    cin>>n;
    bool x=false;
    while(n--)
    {
        if(x)
        {
            cout<<endl;
        }
        else
            x=true;
        int m,c; //m = quantidade de endereços na tabela; c = quantidade de chaves a serem armazenadas 
        cin>>m>>c;
        int v[c],i=0;
        for(int j=0;j<c;j++)
            cin>>v[j];
        for(i=0;i<m;i++)
        {
            cout<<i<<" -> ";
            for(int j=0;j<c;j++){
            //cout<<i<<" ->";
            if(v[j]%m==i)
                cout<<v[j]<<" -> ";
            //if(i+1==m)
                //cout<<" \n";
            }
            cout<<"\n";
        }
    }
    return 0;
}
*/

