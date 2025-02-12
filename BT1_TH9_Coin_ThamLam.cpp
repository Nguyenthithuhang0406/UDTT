#include<bits/stdc++.h>
using namespace std;

int countCoin(long x[], int n, long m){
	sort(x, x + n);
	int i = n - 1;
	int count = 0;
	while( i >= 0 && m > 0){
		int tmp = m / x[i];
		count += tmp;
		if(tmp > 0){
			cout << tmp << " xu " << x[i] << "\n";
		}
		m -= tmp * x[i];
		i--;
	}
	return count;
}

int main(){
	int n = 9;
	long m = 1200;
	long x[n] = {1, 5, 2, 10, 50, 20, 100, 500, 200};
	cout << "Toi thieu " << countCoin(x, n, m) << " xu."; 
	return 0;
}
