#include<bits/stdc++.h>
using namespace std;

double solve1(double a[], int n, double c, int &d){
	int i = 0;
	double sum = 0;
	while(i < n && sum <= c){
		sum += a[i];
		i++;
	}
	d = i - 1;
	if(sum > c){
		sum -= a[i - 1];
		return sum;
	} 
}

int find(char x, string p){
	int n = p.length();
	int i = 0;
	while( i < n && p[i] != x) i++;
	if( i == n) return -1;
	else return i;
}

int boyer_moore_horspool(string p, string t){
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

int main(){
	int n = 8;
	double a[n] = {5, 8, 9, 13, 25, 34, 56, 77}; 
	double c = 123;
	int d = 0;
	cout << "Co the lay nhieu nhat " << d + 1 << " phan tu de duoc gia tri khong vuot qua " << c << " la " << solve1(a, n, c, d) << "\n";
	cout << "Gia tri cac phan tu da lay la: \n";
	for(int i = 0; i <= d; i++) cout << a[i] << " ";
	cout << "\n";
	 
	string q = "child";
	string p = "Hello child !!";
	
	int k = boyer_moore_horspool(q, p);
	if( k < 0) cout << q << " khong la chuoi con cua " << p << "\n";
	else cout << q << " la chuoi con cua " << p << "\n";
	return 0;
}
