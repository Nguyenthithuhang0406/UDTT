#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int l, int r){
	if(l == r){
		if(a[l] % 2 != 0 ) return a[l];
		else return 0;
	}
	
	int m = (l + r) / 2;
	int sumL = sum(a, l, m);
	int sumR = sum(a, m+1, r);
	return sumL + sumR;
}

int main(){
	int n = 10;
	int a[n] = {2, 5, 1, 9, 2, 46, 21, 32, 45, 65};
	cout << "Tong cac so le trong mang la: " << sum(a, 0, n-1) << "\n";
	return 0;
}
