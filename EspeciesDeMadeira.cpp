#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
	
	int n, i; //n = numero de casos teste
	float result, cont;
	map<string, float>mp;
	map<string, float>::iterator it;
	string especie = "";
	
	cin>>n;
	cin.get();
	
	for(i=0; i<=n; i++){
		//cout<<"\ni: "<<i<<endl;
		cont = 0;
		mp.clear();
		if(i > 1){
			cout << endl;	
		}
		while (getline(cin,especie)) { 
			if(especie == "") break;
            mp[especie] = mp[especie]+1;
            cont++;
		}
		result = 1000000/cont;
		for(it = mp.begin(); it != mp.end(); it++){
			it->second = (result*0.0001)*it->second;
			cout<<it->first<<" "<< fixed << setprecision(4) <<it->second<<endl;
		}
	}
	
	return 0;
}
