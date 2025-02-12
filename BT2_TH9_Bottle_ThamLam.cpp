#include<bits/stdc++.h>
using namespace std;

int countBottle(long x[], int n, long d){
	sort(x, x + n);
	int i = 0;
	int count = 0;
	while( i < n && d >= x[i]){
		count ++;
		d -= x[i];
		i++;
	}
	return count;
}

int main(){
	int n = 9;
	long d = 120;
	long x[n] = {1, 5, 2, 10, 50, 20, 100, 500, 200};
	cout << "Toi da " << countBottle(x, n, d) << " chai.";
	return 0;
}
