#include<bits/stdc++.h>
using namespace std;

double maxLe(int a[], int left, int right){
	if(left == right) return (a[left] % 2 == 1) ? a[left] : INT_MIN;
	int mid = (left + right) / 2;
	double minL = maxLe(a, left, mid);
	double minR = maxLe(a, mid + 1, right);
	return minL > minR ? minL : minR;
};

int main(){
	int a[5] = {6, 2, 5, 9, 2};
	cout << "max le: " << maxLe(a, 0, 4);
	return 0;
}
