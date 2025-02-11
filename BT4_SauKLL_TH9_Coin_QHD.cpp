#include<bits/stdc++.h>
using namespace std;

void Q4(int n, vector<int>& c, int m, vector<int>& s, int &t){
	vector<int> dp(m+1, INT_MAX); //dp[j]: so to it nhat de tao so tien j
	vector<int> trace(m+1, -1); //trace[j]: so tien loai cuoi cung duoc chon
	
	dp[0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = c[i]; j <= m; j++){
			if(dp[j - c[i]] != INT_MAX && dp[j - c[i]] + 1 < dp[j]){
				dp[j] = dp[j - c[i]] + 1;
				trace[j] = i;
			}
		}
	}
	
	if(dp[m] == INT_MAX){
		cout << "Khong the doi tien.";
		return;
	}
	
	s.assign(n, 0);
	int money = m;
	while(money > 0){
		int coinIndex = trace[money];
		s[coinIndex] ++;
		money -= c[coinIndex];
	}
	
	t = dp[m];
}
int main(){
	int n = 9;
	vector<int> c = {10, 100, 500, 20, 200, 2, 5, 1, 50};
	int m = 115;
	vector<int> s(n, 0);
	int t;
	
	Q4(n, c, m, s, t);
	cout << "so to toi thieu: " << t << "\n";
	cout << "so to moi loai: \n";
	for(int i = 0; i < n; i++){
		if(s[i] > 0){
			cout << c[i] << " : " << s[i] << " to \n";
		}
	}
	return 0;
}
