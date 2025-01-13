#include<bits/stdc++.h>
using namespace std;

int F1(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;
	if(a >= b) return F1(a % b, b);
	if(a < b) return F1(a, b % a);
};

int F2(int a, int b){
	if(b  == 0) return a;
	while( b > 0){
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main(){
	int a = 16, b = 24;
	cout << "F1: " << F1(a, b) << "\n";
	cout << "F2: " << F2(a,b) << "\n";
	return 0;
}
