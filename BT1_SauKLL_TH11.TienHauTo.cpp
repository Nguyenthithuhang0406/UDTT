#include<bits/stdc++.h>
using namespace std;

string longestOverlap(string a, string b){
	int m = a.length(), n = b.length();
	int max_l = 0;
	
	for(int i = min(m, n); i > 0; i--){
		if(a.substr(m-i) == b.substr(0, i)){
			max_l = i;
			break;
		}
	}
	
	//substr: cat b tu vi tri max_l
	return b.substr(max_l);
}

string concat(string a, string b){
	return a + longestOverlap(a, b);
}

int main(){
	string a = "pref";
	string b = "fix";
	cout << "Xau toa man la: " << concat(a, b);
	return 0;
}
