#include<bits/stdc++.h>
using namespace std;

double sum(double a[], int l, int r){
	if(l == r) return a[l];
	int m = (l + r) / 2;
	double sumL = sum(a, l, m);
	double sumR = sum(a, m+1, r);
	return sumL + sumR;
}

int main(){
	int n = 10;
	double a[n] = {2, 28, 1, 34, 82, 3, 3, 75, 93, 23};
	cout << "Tong cua day la: " << sum(a, 0, n-1);
	return 0;
}
