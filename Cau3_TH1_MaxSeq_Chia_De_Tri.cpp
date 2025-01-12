#include<bits/stdc++.h>
using namespace std;

float maxSeq(float a[], int i, int j){
	if( i == j) return a[i];
	float max = INT_MIN;
	int m = (i + j) / 2;
	float ml = maxSeq(a, i, m);
	float mr = maxSeq(a, m + 1, j);
	max = ml > max ? ml : max;
	max = mr > max ? mr : max;
	return max;
}

int main(){
	int n = 15;
	float a[n] = {2.5, 1.4, 2.8, 9.2, 1.2, 4.3, 9.2, 3.5, 7.2, 13.2, 3.2, 14.4, 12.5, 2.1, 4.6};
	cout << "So thuc lon nhat trong day la: " << maxSeq(a, 0, n-1);
	return 0;
}
