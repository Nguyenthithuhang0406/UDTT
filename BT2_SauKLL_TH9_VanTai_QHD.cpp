#include<bits/stdc++.h>
using namespace std;

void A5(int kt, int n, int m[], int k[], int F[6][21]){
	for(int j = 0; j <= kt; j++) F[0][j] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= kt; j++){
			F[i][j] = F[i-1][j];
			if(k[i] <= j){
				int tmp = m[i] + F[i-1][j-k[i]];
				if(tmp > F[i][j]){
					F[i][j] = tmp;
				}
			}
		}
	}
}

void display(int F[6][21], int n, int kt, int k[]){
	cout << "Max: " << F[n][kt] << "\n";
	int i = n, j = kt;
	int count = 0;
	while(i != 0){
		if(F[i][j] != F[i-1][j]){
			count ++;
			cout << i << " ";
			j -= k[i];
		}
		i--;
	}
	cout << "\n => Can " << count << " kien hang de tong khoi luong lon nhat.\n";
}
int main(){
	int kt = 20;
	int n = 5;
	int m[n+1] = {0, 6, 2, 9, 10, 7};
	int k[n+1] = {0, 6, 2, 9, 1, 3};
	int F[6][21] = {0};
	A5(kt, n, m, k, F);
	display(F, n, kt, k);
	return 0;
}
