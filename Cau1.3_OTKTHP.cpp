#include<bits/stdc++.h>
using namespace std;

double sum(double a[], int l, int r){
	if(l == r){
		if(a[l] > 0) return a[l];
		else return 0;
	}
	
	int m = (l+r) / 2;
	double sumL = sum(a, l, m);
	double sumR = sum(a, m+1, r);
	return sumL + sumR;
}

int main(){
	int n = 10;
	double a[n] = {2, -1, 3, 6, -20, 40, 21, 42, -22, 54};
	cout << "Tong cua cac so duong trong mang la: " << sum(a, 0, n-1) << "\n";
	return 0;
}
