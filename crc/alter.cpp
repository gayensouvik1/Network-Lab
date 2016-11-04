#include <bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[]){

	string data,polynomial;
	cin >> data >> polynomial;
	int alter = atoi(argv[1]);
	
	data[alter] = data[alter]=='1' ? '0' : '1';

	cout << data << endl;
	cout << polynomial << endl;

	return 0;
}