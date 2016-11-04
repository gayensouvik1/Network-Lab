#include <bits/stdc++.h>

using namespace std;



string remainder(string data,string polynomial){

	string rem = "";
	int k = polynomial.length();

	for(int i=0;i<=data.length()-polynomial.length();i++){
		
		if(data[i]=='0'){
			
			continue;
		}
		

		for(int j=0;j<polynomial.length();j++){
			data[i+j] = data[i+j]==polynomial[j] ? '0' : '1';
		}
	}

	for(int i=1;i<k;i++){
		rem += data[data.length()-k+i];
	}
	return rem;

}

int main(){

	string data,polynomial;

	cin >> data >> polynomial;

	int k = polynomial.length();

	string mdata = data;

	for(int i=1;i<k;i++)
		mdata += '0';
	string rem = remainder(mdata,polynomial);

	mdata = data;
	mdata += rem;
	
	cout << mdata<<endl;
	cout << polynomial<<endl;

	return 0;
}