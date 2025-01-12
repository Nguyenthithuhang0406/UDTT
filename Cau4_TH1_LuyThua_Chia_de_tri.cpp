#include<bits/stdc++.h>
using namespace std;

float E(float a, int n){
	if(n == 0) return 1;
	if( n % 2 == 0){
		float t = E(a, n/2);
		return t*t;
	} else return a * E(a, n-1);
}

int main(){
	int n = 4; float a = 2;
	cout << "Ket qua cua luy thua " << a << " mu " << n << " la: " << E(a, n);
	return 0;
}
