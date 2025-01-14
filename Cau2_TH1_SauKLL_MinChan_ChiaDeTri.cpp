#include<bits/stdc++.h>
using namespace std;

double minChan(int a[], int left, int right){
	if(left == right) return (a[left] % 2 == 0) ? a[left] : INT_MAX;
	int mid = (left + right) / 2;
	double minL = minChan(a, left, mid);
	double minR = minChan(a, mid + 1, right);
	return minL < minR ? minL : minR;
};

int main(){
	int a[5] = {6, 2, 5, 9, 2};
	cout << "min chan: " << minChan(a, 0, 4);
	return 0;
}
