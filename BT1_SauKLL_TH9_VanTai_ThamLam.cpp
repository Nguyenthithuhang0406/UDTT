#include<bits/stdc++.h>
using namespace std;

void A4(float t[], int n, float m){
	sort(t, t + n);
	int i = n-1;
	while(i >= 0 && m > 0){
		if(m >= t[i]){
			cout << t[i] << " ";
			m -= t[i];
		}
		i--;
	}
}
int main(){
	int n = 5;
	float t[n] = {2.4, 5, 1.2, 3, 7};
	float m  = 10; 
	cout << "Can cac xe tai co tai trong sau: \n";
	A4(t, n, m);
	return 0;
}
