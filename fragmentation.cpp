#include <bits/stdc++.h>

using namespace std;

string s;
int max_size;
int header_size;

struct packet
{
	int offset;
	bool mf;
	string data;
};

struct packet pck[1000];

int main(){

	cin >> max_size;
	cin >> s;

	max_size /= 8;
	int total_size = s.length();

	int cur = -1;

	for(int i=0;i<total_size;i++){
		if(i%max_size==0){
			cur++;
			pck[cur].data = "";
			pck[cur].offset = i;
		}
		pck[cur].data += s[i];
	}

	for(int i=0;i<=cur;i++){
		cout << pck[i].offset<<" "<<pck[i].data<<endl;
	}

	return 0;
}