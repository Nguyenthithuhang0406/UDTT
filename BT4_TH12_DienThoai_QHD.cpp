#include<bits/stdc++.h>
using namespace std;

struct dienThoai{
	string nhanHieu;
	int kichThuoc;
	double giaBan;
};

void init(vector<dienThoai>& d){
	d.push_back({});
	dienThoai dt1 = {"Samsung", 13, 5000000};
	dienThoai dt2 = {"Apple", 10, 7000000};
	dienThoai dt3 = {"Oppo", 14, 8000000};
	dienThoai dt4 = {"Xiaomi", 12, 7000000};
	dienThoai dt5 = {"Vivo", 13, 12000000};
	d.push_back(dt1);
	d.push_back(dt2);
	d.push_back(dt3);
	d.push_back(dt4);
	d.push_back(dt5);
}

void Q1(vector<dienThoai> d, int n, int s, vector<vector<double>>& f){
	for(int j = 0; j <= s; j++) f[0][j] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= s; j++){
			f[i][j] = f[i-1][j];
			if(d[i].kichThuoc <= j){
				int tmp = d[i].giaBan + f[i-1][j - d[i].kichThuoc];
				if(tmp > f[i][j]){
					f[i][j] = tmp;
				}
			}
		}
	}
}

void display(dienThoai dt){
	cout << "Hang: " << dt.nhanHieu << " , gia ban: " << dt.giaBan << "\n";
}

void solve(vector<dienThoai> d, int n, int s, vector<vector<double>>& f){
	Q1(d, n, s, f);
	cout << "Tong gia ban lon nhat la: " << f[n][s] << "\n";
	cout << "Gom cac dien thoai: " << "\n";
	int count = 0;
	int i = n, j = s;
	while(i != 0){
		if(f[i][j] != f[i-1][j]){
			display(d[i]);
			count ++;
			j -= d[i].kichThuoc;
		}
		i--;
	}
	cout << "=> Nhieu nhat " << count << " chiec dien thoai.";
}

int main(){
	int n = 5;
	vector<dienThoai> d;
	init(d);
	int s = 23;
	vector<vector<double>> f(n + 1, vector<double>(s + 1, 0));
	solve(d, n, s, f);
	return 0;
}
