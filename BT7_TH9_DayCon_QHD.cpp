#include<bits/stdc++.h>
using namespace std;

void Q3(int n, int a[], int L[], int T[]){
	for(int i = n; i >= 0; i--){
		int jmax = n+1;
		for(int j = i+1; j <= n + 1; j++){
			if(a[j] > a[i] && L[j] > L[jmax]){
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}

void display(int T[], int n, int a[]){
	int k = T[0];
	cout << "Day con: ";
	while(k != n+1){
		cout << "a[" << k << "] : " << a[k] << " ";
		k = T[k];
	}
}
int main(){
	int n = 10;
	int a[n+2] = {INT_MIN, 3, 1, 7, 8, 9, 2, 5, 6, 4, 10, INT_MAX};
	int L[n+2] = {1};
	int T[n+2] = {0};
	Q3(n, a, L, T);
	display(T, n, a);
	return 0;
}
