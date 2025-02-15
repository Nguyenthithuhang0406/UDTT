#include<bits/stdc++.h>
using namespace std;

bool compareTo(string a, string b){
	return a.length() > b.length();
}

string G(string d[], int n, int k){
	string newD[n];
	for(int i = 0; i < n; i++) newD[i] = d[i];
	sort(newD, newD+n, compareTo);
	string p = "";
	for(int i = 0; i < n; i++){
		if(p.length() + newD[i].length() <= k){
			p += newD[i];
		}
		if(p.length() == k) return p;
	}
	return p.substr(0, k);
}

int find(char x, string p){
	int n = p.length() - 1;
	int i = 0;
	while(i <= n && p[i] != x) i++;
	if(i > n ) return -1;
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
		if(k < 0) return i + 1;
		else{
			int x = find(t[i], p);
			if(x < 0) i = i + v;
			else i = i + v - x - 1;
		}
	}
	return -1;
}

int count(string d[], int n, int dd[], string w){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(Boyer_Moore_Horspool(w, d[i]) >= 0){
			cnt ++;
			dd[i] = 1;
		} 
	}
	return cnt;
}

void z_algo(string s, int z[]){
	int n = s.length(), left = 0, right = 0;
	for(int i = 1; i < n; i++){
		if(i > right){
			left = right = i;
			while(right < n && s[right - left] == s[right]) right ++;
			z[i] = right - left;
			right --;
		}else{
			if(z[i-left] < right - i + 1){
				z[i] = z[i - left];
			}else{
				left = i;
				while(right < n && s[right - left] == s[right]) right ++;
				z[i] = right - left;
				right --;
			}
		}
	}
}

int count(string s, string w){
	string newS = w + "$" + s;
	int z_size = newS.length();
	int z[z_size] = {0};
	z_algo(newS, z);
	int cnt = 0;
	int w_length = w.length();
	for(int i = 0; i < z_size; i++){
		if(z[i] == w_length) cnt ++;
	}
	return cnt;
}

int main(){
	int n = 5;
	string d[n] = {"This is a child story", "Every child loves toys", "A good childhood is precious", "Children play outside", "We should care for every child"};
	int k = 55;
	cout << "Xau moi co do dai dung bang " << k << " bang cach noi cac xau voi so luong la it nhat la: " << G(d, n, k) << "\n";
	
	int dd[n] = {0};
	int cnt = count(d, n, dd, "child");
	cout << "Tu child xuat hien trong xau cua danh sach d " << cnt << " lan. \n";
	if(cnt > 0){
		cout << "Cac xau xuat hien tu child la: \n";
		for(int i = 0; i < n; i++){
			if(dd[i] == 1) cout << d[i] << "\n";
		}
	}
	cout << "Nhung xau co " << d[0] << " la xau con la: \n";
	for(int i = 1; i < n; i++){
		int cnt = count(d[i], d[0]);
		if(cnt > 0) cout << d[i] << " : " << cnt << "\n";
	}
	
	return 0;
}
