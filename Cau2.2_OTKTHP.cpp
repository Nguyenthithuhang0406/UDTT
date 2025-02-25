#include<bits/stdc++.h>
using namespace std;

double solve1(double a[], int n, double c, int &count){
	double sum = 0;
	int i = n-1;
	while(i >= 0 && sum <= c){
		sum += a[i];
		i--;
		count ++;
	}
	return sum;
}

int find(char x, string p){
	int i = 0;
	int n = p.length();
	while(i < n && p[i] != x) i++;
	if(i == n) return -1;
	else return i;
}

int Boyer_Moore_Horspool(string p, string t){
	int v = p.length(), i = v - 1;
	int n = t.length();
	while(i < n){
		int k = v - 1;
		while(k > -1 && t[i] == p[k]){
			k--;
			i--;
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

void solve2(string p, string t){
	int pos = Boyer_Moore_Horspool(p,t);
	if(pos == -1) cout << "Xau " << p << " khong xuat hien trong xau " << t << "\n";
	else cout << "Nhung vi tri xuat hien cua xau " << p << " trong xau " << t << " la: ";
	string r = "";
	int n = p.length();
	for(int i = 0; i < n; i++) r += " ";
	while(pos != -1){
		cout << pos << " ";
		t.replace(pos, n, r);
		pos = Boyer_Moore_Horspool(p,t);
	}
}

int main(){
	int n = 8;
	double a[n] = {2, 6, 34, 84, 93, 110, 113, 132};
	double c = 250;
	int count = 0;
	cout << "Can lay it nhat " << count << " phan tu de co tong la " << solve1(a, n, c, count) << " lon hon " << c << "\n";
	cout << "Cac so co the lay la: \n";
	for(int i = 1; i <= count; i++){
		cout << a[n-i] << " ";
	}
	cout << "\n";
	
	string p = "child";
	string q = "Helle child!! welcome child.";
	solve2(p, q);
	return 0;
}
