#include <bits/stdc++.h>

using namespace std;

int main() {
	
	map<string, string>mp;
	map<string, string>::iterator it;
	string teste;
	
	mp.insert({"brasil", "Feliz Natal!"});
	mp.insert({"alemanha", "Frohliche Weihnachten!"});
	mp.insert({"austria", "Frohe Weihnacht!"});
	mp.insert({"coreia", "Chuk Sung Tan!"});
	mp.insert({"espanha", "Feliz Navidad!"});
	mp.insert({"grecia", "Kala Christougena!"});
	mp.insert({"estados-unidos", "Merry Christmas!"});
	mp.insert({"inglaterra", "Merry Christmas!"});
	mp.insert({"australia", "Merry Christmas!"});
	mp.insert({"portugal", "Feliz Natal!"});
	mp.insert({"suecia", "God Jul!"});
	mp.insert({"turquia", "Mutlu Noeller"});
	mp.insert({"argentina", "Feliz Navidad!"});
	mp.insert({"chile", "Feliz Navidad!"});
	mp.insert({"mexico", "Feliz Navidad!"});
	mp.insert({"antardida", "Merry Christmas!"});
	mp.insert({"canada", "Merry Christmas!"});
	mp.insert({"irlanda", "Nollaig Shona Dhuit!"});
	mp.insert({"belgica", "Zalig Kerstfeest!"});
	mp.insert({"italia", "Buon Natale!"});
	mp.insert({"libia", "Buon Natale!"});
	mp.insert({"siria", "Milad Mubarak!"});
	mp.insert({"marrocos", "Milad Mubarak!"});
	mp.insert({"japao", "Merii Kurisumasu!"});
	
	while (!cin.eof()) {
		cin>>teste;
		
		it = mp.find(teste); 

		if (it!=mp.end()){
			cout<<it->second<<endl;
		}
		else{
			cout<<"--- NOT FOUND ---"<<endl;
		}
		//fflush(stdin);
	}
	
	return 0;
}
