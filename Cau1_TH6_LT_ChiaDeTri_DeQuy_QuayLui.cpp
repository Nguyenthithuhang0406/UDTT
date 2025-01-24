#include<bits/stdc++.h>
using namespace std;

void show(string g[], string N[], int a[], int n, int count){
	cout << "Cach " << count << "\n";
	for(int i = 0; i < n; i++){
		cout << "ghe " << g[i] << " : " << N[a[i]] << "\n";
	}
}

void A1(string g[], string N[], int a[], int dd[], int n, int k, int &count){
	for(int i = 0; i < n; i++){
		if(dd[i] == 0){
			a[k] = i;
			
			if(k == n - 1){
				count ++;
				show(g, N, a, n, count);
			}else{
				dd[i] = 1;
				A1(g, N, a, dd, n, k+1, count);
				dd[i] = 0;
			}
		}
	}
}

int main(){
	string g[4] = {"A", "B", "C", "D"};
	string N[4] = {"Tung", "Cuc", "Truc", "Mai"};
	int a[4] = {0};
	int dd[4] = {0};
	int n = 4,  k = 0, count = 0;
	A1(g, N, a, dd, n, k, count);
	cout << "Co tat ca " << count << " cach xep!";
	return 0;
}
