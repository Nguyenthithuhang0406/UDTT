#include<bits/stdc++.h>
using namespace std;

struct chuyenBay{
	string soHieu;
	int giaVe;
	int soGhe;
};

void init(vector<chuyenBay>& b){
	chuyenBay cb1 = {"VN01", 800000, 3};
	chuyenBay cb2 = {"VN02", 500000, 5};
	chuyenBay cb3 = {"VN03", 1000000, 2};
	chuyenBay cb4 = {"VN04", 120000, 8};
	chuyenBay cb5 = {"VN05", 90000, 12};
	chuyenBay cb6 = {"VN06", 9000000, 4};
	b.push_back(cb1);
	b.push_back(cb2);
	b.push_back(cb3);
	b.push_back(cb4);
	b.push_back(cb5);
	b.push_back(cb6);
}

void display(chuyenBay cb){
	cout << cb.soHieu << " , gia ve " << cb.giaVe << " tai ghe " << cb.soGhe << "\n";
}

void view(vector<chuyenBay> b, int n, int i){
	if(i == n) return;
	if(b[i].giaVe > 700000) display(b[i]);
	view(b, n, i+1);
}

chuyenBay minGia(vector<chuyenBay> b, int l, int r){
	if(l < r){
		int mid = (l + r) / 2; 
		chuyenBay minL = minGia(b, l, mid);
		chuyenBay minR = minGia(b, mid+1, r);
		if(minL.giaVe < minR.giaVe) return minL;
		else return minR;
	}return b[l];
}

void display2(int tmp[], vector<chuyenBay> b, int k, int count){
	cout << "Phuong an " << count << "\n";
	for(int i = 0; i < k; i++ ){
		cout << b[tmp[i]].soHieu;
		if(i < k-1) cout << " , ";
	}
	cout << "\n";
}

void A3(vector<chuyenBay> b, int tmp[], int n, int k, int pass, int id, int &count){
	for(int i = pass; i< n; i++){
		tmp[id] = i;
		if(id == k-1){
			count += 1;
			display2(tmp, b, k, count);
		}else{
			A3(b, tmp, n, k, i + 1, id + 1, count);
		}
	}
}

int main(){
	int n = 6;
	vector<chuyenBay> b;
	init(b);
	view(b, n, 0);
	chuyenBay m = minGia(b, 0, n-1);
	cout << "chuyen bay co gia ve thap nhat la: \n";
	display(m);
	int count = 0;
	int k = 4;
	int tmp[4] = {0};
	A3(b, tmp, n, k, 0, 0, count);
	cout << "Co tat ca " << count << " phuong an!";
	return 0;
}
