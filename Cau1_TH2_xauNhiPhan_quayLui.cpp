#include<bits/stdc++.h>
using namespace std;

void A1(int n, string s, char a, char b){
	if(s.length() == n){
		cout << s << "\n";
	}
	else{
		A1(n, s + a, a, b);
		A1(n, s + b, a, b);
	}
}

int main(){
	int n = 3;
	cout << "Cac chuoi nhi phan co do dai " << n << " la: \n";
	A1(n, "", '0', '1');
	cout << "Cac chuoi chua 2 ky tu a va b co do dai " << n << " la: \n";
	A1(n, "", 'a', 'b');
	return 0;
}
