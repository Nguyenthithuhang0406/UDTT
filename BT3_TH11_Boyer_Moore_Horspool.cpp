#include<bits/stdc++.h>
using namespace std;

int find(char x, string p){
	int i = 0;
	int n = p.length() - 1;
	while(i <= n && p[i] != x) i++;
	if(i > n) return -1;
	else return i;
}

int Boyer_Moore_Horspool(string p, string t){
	int v = p.length(), i = v - 1;
	int n = t.length();
	while(i < n){
		int k = v - 1;
		while(k > -1 && t[i] == p[k]){
			i--;
			k--;
		}
		if(k < 0) return i+1;
		else{
			int x = find(t[i], p);
			if(x < 0) i = i + v;
			else i = i + v - x - 1;
		}
	}
	return -1;
}

void replace(string p, string &t, string q){
	int p_length = p.length();
	int pos = Boyer_Moore_Horspool(p, t);
	while(pos != -1){
		t.replace(pos, p_length, q );
		pos = Boyer_Moore_Horspool(p, t);
	}
}

int main(){
	string s = "Gia tri tien te la 1000 dong va 1000 van la gia tri lon.";
	string p = "1000";
	int k = Boyer_Moore_Horspool(p, s);
	if(k < 0 ) cout << "Xau '" << p << "' khong co trong xau '" << s << "'\n";
	else{
		cout << "Xau '" << p << "' xuat hien dau tien trong xau '" << s << "' tai vi tri " << k << "\n";
		string q = "motnghindong";
		replace(p, s, q);
		cout << "Xau sau khi thay the la: \n";
		cout << s;
	}
	
	return 0;
}
