#include<bits/stdc++.h>
using namespace std;

void Q2(int w[], int v[], int n, int m, int F[6][16]){
	for(int j = 0; j <= m; j++) F[0][j] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			F[i][j] = F[i-1][j]; //khong lay goi thu i
			if(w[i] <= j){
				int tmp = v[i] + F[i-1][j - w[i]];
				if(tmp > F[i][j]){
					F[i][j] = tmp; //lay goi thu i
				}
			}
		}
	}
}

void display(int w[], int n, int m, int F[6][16]){
	cout << "Max: " << F[n][m] << "\n";
	int count = 0;
	int i = n, j = m;
	while(i != 0){
		if(F[i][j] != F[i-1][j]){
			count ++;
			cout << i << " " ;
			j = j - w[i]; //lay goi thu i
		}
		i--;
	}
	cout << "=> Lay toi da " << count << " goi qua.";
}
int main(){
	int n = 5;
	int w[n+1] = {0, 1, 5, 2, 3, 7};
	int v[n+1] = {0, 12, 11, 9, 23, 4};
	int m = 15;
	int F[6][16] = {0};
	Q2(w, v, n, m, F);
	display(w, n, m, F);
	return 0;
}

// 0...m
//0
//...
//n
