#include<bits/stdc++.h>
using namespace std;

int deQuy(int n){
	if(n == 0) return 0;
	return n % 10 + deQuy(n/10);
}

int lap(int n){
	int sum = 0;
	while(n > 0){
		sum += n% 10;
		n /= 10;
	}
	return sum;
}

int main(){
	int n = 24;
	cout << "Tong cac chu so bang de quy la: " << deQuy(n) << "\n";
	cout << "Tong cac chu so bang lap la: " << lap(n) << "\n";
	return 0;
}
