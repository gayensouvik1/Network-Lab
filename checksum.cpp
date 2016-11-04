#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main(){


	for(int i=0;i<10;i++)
		cin >> hex >> arr[i];

	int sum = 0;

	for(int i=0;i<10;i++){
		if(i==5) continue;
		sum += arr[i];
		if(sum/(1<<16)){
			sum %= 1<<16;
			sum++;
			sum %= 1<<16;
		}
	}
	sum = ~sum;
	sum += 1<<16;

	cout << hex << sum;

	return 0;
}