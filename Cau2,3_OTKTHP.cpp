#include<bits/stdc++.h>
using namespace std;

struct goiHang{
	int m;
	double v;
};

void init(vector<goiHang>& a){
	goiHang g1 = {3, 2};
	goiHang g2 = {6, 3};
	goiHang g3 = {2, 12};
	goiHang g4 = {4, 16};
	goiHang g5 = {1, 2};
	goiHang g6 = {7, 4};
	goiHang g7 = {8, 10};
	goiHang g8 = {2, 3};
	a.push_back(g1);
	a.push_back(g2);
	a.push_back(g3);
	a.push_back(g4);
	a.push_back(g5);
	a.push_back(g6);
	a.push_back(g7);
	a.push_back(g8);
}

bool compareTo(goiHang a, goiHang b){
	return a.v < b.v;
}

int thamLam(vector<goiHang>& a, int n, double c){
	sort(a.begin(), a.end(), compareTo);
	int i = 0;
	int count  = 0;
	while(i < n && c >= a[i].v){
		c = c - a[i].v;
		count ++;
		i++;
	}
	if(c == 0) return count;
	else return -1;
}

void QHD(vector<goiHang> a, int n, int m, vector<vector<double>>& f){
	for(int j = 0; j <= m; j++){
		f[0][j] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i-1][j];
			if(a[i].m <= j){
				double tmp = f[i-1][j - a[i].m] + a[i].v;
				if(tmp > f[i][j]){
					f[i][j] = tmp;
				}
			}
		}
	}
}

void solve2(vector<goiHang> a, int n, int m){
	vector<vector<double>> f(n+1, vector<double> (m+1, 0));
	QHD(a, n, m, f);
	cout << "Gia tri lon nhat co the dat duoc ma tong khoi luong khong vuot qua " << m << " la: " << f[n][m] << "\n";
	cout << "Cac goi hang co the lay la: \n";
	int i = n, j = m;
	while( i != 0){
		if(f[i][j] != f[i-1][j]){
			cout << "goi hang co khoi luong " << a[i].m << " va gia tri " << a[i].v << "\n";
			j = j - a[i].m;
		}
		i--;
	}
}
int main(){
	int n = 8;
	vector<goiHang> a;
	init(a);
	double c = 4;
	int cnt = thamLam(a, n, c);
	if(cnt < 0) cout << "Khong the lay nhieu nhat de dat duoc mot gia tri dung bang " << c << "\n";
	else{
		cout << "Can lay nhieu nhat " << cnt << " goi hang de dat duoc gia tri dung bang " << c << "\n";
		cout << "Cac goi hang co the lay la: \n";
		for(int i = 0; i < cnt; i ++){
			cout << "Goi hang co khoi luong " << a[i].m << " va gia tri " << a[i].v << "\n";
		}
	}
	int m = 13;
	solve2(a, n, m);
	return 0;
}
	
