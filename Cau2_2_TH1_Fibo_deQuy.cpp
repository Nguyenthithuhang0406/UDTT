#include<bits/stdc++.h>
using namespace std;

int F1(int n){
	if(n <= 2) return 1;
	return F1(n-1) + F1(n-2);
}

int F2(int n){
	int a[n+1];
	a[1] = a[2] = 1;
	if( n > 2){
		for(int i = 3; i <= n; i++){
			a[i] = a[i-1] + a[i-2];
		}
	}
	return a[n];
}
int main(){
	int n = 7, m = 5;
	cout << "F1:" << F1(n) << " " << F1(m) << "\n";
	cout << "F2: " << F2(n) << " " << F2(m) << "\n";
	return 0;
}
