#include<bits/stdc++.h>
using namespace std;

double Tong(double a[], int left, int right){
	if(left == right) return (a[left] > 0) ? a[left] : 0;
	int mid = (left + right) / 2;
	double sumL = Tong(a, left, mid);
	double sumR = Tong(a, mid + 1, right);
	return sumL + sumR;
};

int main(){
	double a[5] = {2.1, -1.2, -1.4, 3.2, 4.2};
	cout << "Tong: " << Tong(a, 0, 4);
	return 0;
}
