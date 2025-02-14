#include<bits/stdc++.h>
using namespace std;

struct quatBan{
	string tenHangSX;
	string mauSac;
	double giaBan;
};

void init(vector<quatBan>& d){
	quatBan q1 = {"Senko", "trang", 500000};
	quatBan q2 = {"Panasonic", "den", 300000};
	quatBan q3 = {"Asia", "bac", 400000};
	quatBan q4 = {"Toshiba", "trang", 1000000};
	quatBan q5 = {"Lifan", "xanh", 300000};
	quatBan q6 = {"Kangaroo", "trang", 2000000};
	d.push_back(q1);
	d.push_back(q2);
	d.push_back(q3);
	d.push_back(q4);
	d.push_back(q5);
	d.push_back(q6);
}

void display(quatBan q){
	cout << "Hang SX: " << q.tenHangSX << " , gia ban: " << q.giaBan;
}

bool compareTo(quatBan a, quatBan b) {
    return a.giaBan > b.giaBan;
}

int G1(vector<quatBan>& d, int n, double p, int dd[]){
	sort(d.begin(), d.end(), compareTo);
	int i = 0;
	int count = 0;
	while (i < n && p > 0){
		if(p >= d[i].giaBan){
			p -= d[i].giaBan;
			count ++;
			dd[i] = 1;
		}
		i++;
	}
	return count;
}

void solve(vector<quatBan> d, int n, double p, int dd[]){
	int count = G1(d, n, p, dd);
	cout << "Voi so tien " << p << " mua duoc nhieu nhat " << count << " chiec quat. \n";
	if(count > 0){
		cout << "Danh sach quat mua duoc la: \n";
		for(int i = 0; i < n; i++){
			if(dd[i] == 1){
				display(d[i]);
				cout << "\n";
			}
		}
	}
}
int main(){
	int n = 6;
	vector<quatBan> d;
	init(d);
	int dd[n] = {0};
	double p = 1300000;
	solve(d, n, p, dd);
	return 0;
}
