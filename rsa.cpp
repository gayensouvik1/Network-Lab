#include <bits/stdc++.h>

using namespace std;
#define ll long long

long long p,q,phi,n,e,d;
ll enc[500];

ll gcd(ll a,ll b)
{
	if(a%b==0)
		return b;

	return gcd(b,a%b);
}

ll public_key(){
	for(ll i=2;i<phi;i++){
		if(gcd(i,phi)==1)
			return i;
	}
	return -1;
}

ll private_key(){
	for(ll i=0;i<phi;i++){
		ll temp = phi*i+1;
		if(temp%e==0 && gcd(phi,temp/e)==1)
			return temp/e;
	}
	return -1;
}

ll modular_exp(ll base,ll exp,ll mod){

	ll temp = base;
	ll res = 1;
	while(exp>0){
		if(exp%2==1){
			res *= temp;
			res %= mod;
		}
		temp*=temp;
		temp %= mod;
		exp/=2;
	}
	return res;

}

void encrypt(string message){

	for(int i=0;i<message.length();i++){
		ll tmp = (ll)message[i];
		enc[i] = modular_exp(tmp,e,n);
		cout <<enc[i];
	}
	cout<<endl;
	
}

string decrypt(ll len){
	string message = "";
	for(int i=0;i<len;i++){
		ll tmp = enc[i];
		tmp = modular_exp(tmp,d,n);
		char ch = tmp;
		message += ch;
	}
	return message;

}

int main(){

	ll p,q;
	string message;

	cin >> message;

	cin >> p >> q;

	n = p*q;
	phi = (p-1)*(q-1);

	e = public_key();
	d = private_key();

	encrypt(message);
	ll len = message.length();
	cout << decrypt(len)<<endl;

	return 0;
}