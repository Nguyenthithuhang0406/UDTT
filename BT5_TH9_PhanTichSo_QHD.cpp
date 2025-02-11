#include<bits/stdc++.h>
using namespace std;

int Q1(int n){
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	
	for(int j = 1; j <= n; j++){
		for(int i = j; i <= n; i++ ){
			dp[i] += dp[i-j] ;
		}
	}
	
	return dp[n];
}
int main(){
	int n = 5;
	cout << "Co " << Q1(n) << " cach de phan tich " << n << " thanh tong cua cac so nguyen duong."; 
	return 0;
}

// 0....n
//0
//..
//m
