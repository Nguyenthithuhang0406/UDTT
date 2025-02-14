#include<bits/stdc++.h>
using namespace std;

struct mayTinh{
	string hangSX;
	string moTa;
	double giaBan;
};

void init(vector<mayTinh>& d){
	mayTinh mt1 = {"DELL", "CPU i7 1265H-RAM 16GB - 15.7 inchs - new", 900};
	mayTinh mt2 = {"HP", "CPU i7 1265H-RAM 8GB - 14 inchs - new", 800};
	mayTinh mt3 = {"ACER", "CPU i5 1265H-RAM 16GB - 14 inchs - new", 700};
	mayTinh mt4 = {"ASUS", "CPU i5 1265H-RAM 16GB - 15.7 inchs - new", 600};
	mayTinh mt5 = {"LENOVO", "CPU I7 1265H-RAM 8GB - 13.7 inchs - new", 500};
	mayTinh mt6 = {"TOSHIBA", "CPU I5 1265H-RAM 16GB - 14.7 inchs - new", 400};
	d.push_back(mt1);
	d.push_back(mt2);
	d.push_back(mt3);
	d.push_back(mt4);
	d.push_back(mt5);
	d.push_back(mt6);
}

void z_algo(string s, int z[]){
	int n = s.length(), left = 0, right = 0;
	for(int i = 1; i < n; i++){
		if( i > right){
			left = right = i;
			while(right < n && s[right - left] == s[right]){
				right ++;
			}
			z[i] = right - left;
			right --;
		}else if(z[i-left] < right - i + 1){
			z[i] = z[i - left];
		}else{
			left = i;
			while(right < n && s[right - left] == s[right]){
				right ++;
			}
			z[i] = right - left;
			right --;
		}
	}
}

bool z_app(string t, string p){
	int p_size = p.length(), t_size = t.length();
	string new_S = p + "$" + t;
	int n = new_S.length();
	int z[n] = {0};
	z_algo(new_S, z);
	int i = 0;
	while(i < n && z[i] != p_size) i++;
	if(i == n) return false;
	else return true;
}

int countMT(vector<mayTinh> d, string t, int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(z_app(d[i].moTa, t)) count ++;
	}
	return count;
}

int main(){
	int n = 6;
	vector<mayTinh> d;
	init(d);
	double m = 1000;
	string t = "14 inchs";
	int cnt = countMT(d, t, n);
	if(cnt == 0) cout << "Khong co may tinh co kich thuoc la " << t << "\n";
	else cout << "Co " << cnt << " may tinh co kich thuoc la " << t << "\n";
	return 0;
}
