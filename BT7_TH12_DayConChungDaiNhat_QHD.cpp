#include<bits/stdc++.h>
using namespace std;

vector<int> LCS(int a[], int b[], int n, int m){
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	//truy nguoc tim day con chung
	vector<int> c;
	int i = n, j = m ;
	while(i > 0 && j > 0){
		if(a[i-1] == b[j-1]){
			c.push_back(a[i-1]);
			i--; j--;
		}else{
			if(dp[i-1][j] >= dp[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}
	
	reverse(c.begin(), c.end());
	return c;
}

void display(vector<int> c){
	for(int x : c){
		cout << x << " ";
	}
}

int main(){
	int n = 6, m = 6;
	int a[n] = {1, 3, 4, 1, 2, 8};
	int b[m] = {3, 4, 1, 2, 1, 8};
	
	vector<int> c = LCS(a, b, n, m);
	cout << "Day con dai nhat la: ";
	display(c);
	return 0;
}
