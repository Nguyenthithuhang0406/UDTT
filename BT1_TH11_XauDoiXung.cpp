#include<bits/stdc++.h>
using namespace std;

bool A1(string s){
	int i = 0;
	int j = s.length() - 1;
	while(i < j){
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

string A2(string s, int k){
	int i = k - 1, j = k + 1;
	int n = s.length() - 1;
	while(i >= 0 && j <= n && s[i] == s[j]){
		i--;
		j++;
	}
	string newS = "";
	for(int k = i + 1; k <= j-1; k++) newS += s[k];
	return newS;
}

int main(){
	string s = "helaleh world";
	bool ktra = A1(s);
	if(ktra == true) cout << "Xau ky tu " << s << " la xau doi xung. \n";
	else cout << "Xau ky tu " << s << " khong la xau doi xung. \n";
	int k = 3;
	cout << "Xau con doi xung dai nhat co tam la s[" << k << "] la: " << A2(s, k);
	return 0;
}
