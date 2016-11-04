#include <bits/stdc++.h>

using namespace std;

bool remainder(string data,string polynomial){

	int k = polynomial.length();
	
	for(int i=0;i<=data.length()-polynomial.length();i++){
		
		if(data[i]=='0'){
			
			continue;
		}
		

		for(int j=0;j<polynomial.length();j++){
			data[i+j] = data[i+j]==polynomial[j] ? '0' : '1';
		}
	}


	for(int i=0;i<k;i++){
		if(data[data.length()-k+i]=='1')
			return false;
	}
	return true;

}

int main(){
	string data,polynomial;
	cin >> data >> polynomial;

	if(remainder(data,polynomial))
		cout << "Error free"<<endl;
	else
		cout << "Error occured"<<endl;
}