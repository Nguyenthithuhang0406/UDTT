#include<bits/stdc++.h>
using namespace std;

struct laptop{
	string tenHangSX;
	string cauHinh;
	double giaBan;
};

void init(vector<laptop>& d){
	laptop l1 = {"HP", "CPU 2.5GHz upto 3.5GHZ-RAM 16GB-SSD 512GB", 15000000};
	laptop l2 = {"ACER", "CPU 2.5GHz upto 3.5GHZ-RAM 8GB-SSD 512GB", 10000000};
	laptop l3 = {"ASUS", "CPU 2.5GHz upto 3.5GHZ-RAM 16GB-SSD 258GB", 12000000};
	laptop l4 = {"DELL", "CPU 3.5GHz upto 3.5GHZ-RAM 8GB-SSD 512GB", 14000000};
	laptop l5 = {"LENOVO", "CPU 2.5GHz upto 3.5GHZ-RAM 8GB-SSD 512GB", 13000000};
	d.push_back(l1);
	d.push_back(l2);
	d.push_back(l3);
	d.push_back(l4);
	d.push_back(l5);
}

int find(char x, string p){
	int n = p.length() - 1;
	int i = 0;
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
		if(k < 0) return i + 1;
		else{
			int x = find(t[i], p);
			if(x < 0) i = i + v;
			else i = i + v - x - 1;
		}
	}
	return -1;
}

void z_algo(string s, int z[]){
	int n = s.length(), left = 0, right = 0;
	for(int i = 1; i < n; i++){
		if( i > right){
			left = right = i;
			while(right < n && s[right - left] == s[right]) right ++;
			z[i] = right - left;
			right --;
		}else{
			if(z[i - left] < right - i + 1){
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

bool F2(string s, string w){
	int n = s.length();
	int w_length = w.length();
	int z_size = n + w_length + 1;
	int z[z_size] = {0};
	string newS = w + "$" + s;
	z_algo(newS, z);
	int i = 0;
	while(i < z_size && z[i] != w_length) i++;
	if(i == z_size) return false;
	else return true;
}

int F3(vector<laptop> d, string w, int n){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(Boyer_Moore_Horspool(w, d[i].cauHinh) >= 0){
			cnt ++;
		}
	}
	return cnt;
}

void display(laptop l){
	cout << "Hang " << l.tenHangSX << ", cau hinh " << l.cauHinh << ", gia ban " << l.giaBan << "\n";
}

int F4(vector<laptop> d, int n, int dd[], string w){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(F2(d[i].cauHinh, w)){
			cnt ++;
			dd[i] = 1;
		}
	}
}

int main(){
	int n = 5;
	vector<laptop> d;
	init(d);
	cout << "Co " << F3(d, "RAM 16GB", n) << " chiec may tinh trong danh sach d co thong tin bo nho trong la RAM 16GB" << "\n";
	int dd[n] = {0};
	int count = F4(d, n, dd, "SSD");
	cout << "Co " << count << " chiec may tinh trong danh sach d su dung o cung loai SSD.\n";
	if(count > 0){
		cout << "Danh sach laptop su dung o cung loai SSD: \n ";
		for(int i = 0; i < n; i++){
			if(dd[i] = 1){
				display(d[i]);
			}
		}
	}
	return 0;
}
