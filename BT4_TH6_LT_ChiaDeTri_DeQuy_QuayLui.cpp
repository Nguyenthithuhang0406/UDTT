#include<bits/stdc++.h>
using namespace std;

struct chuyenBay{
	string soHieu;
	int giaVe;
	int ghe;
};

void init(chuyenBay b[]){
	b[0] = {"VN001", 500000, 21};
	b[1] = {"VN002", 12000000, 32};
	b[2] = {"VN003", 900000, 12};
	b[3] = {"VN004", 700000, 10};
	b[4] = {"VN005", 800000, 24};
	b[5] = {"VN006", 1000000, 26};
	b[6] = {"VN007", 200000, 12};
}

void display(chuyenBay cb){
	cout << "Chuyen bay: " << cb.soHieu << " , gia ve: " << cb.giaVe << " , so ghe: " << cb.ghe << "\n";
}

void A1(chuyenBay b[], int index, int n){
	if(index == n) return;
	if(b[index].giaVe > 700000) display(b[index]);
	A1(b, index+1, n);
}

chuyenBay A2(chuyenBay b[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		chuyenBay minL = A2(b, left, mid);
		chuyenBay minR = A2(b, mid + 1, right);
		return minL.giaVe < minR.giaVe ? minL : minR;
	}else{
		return b[left];
	}
}

void show(chuyenBay b[], int a[], int k, int count){
	cout << "Cach " << count << "\n";
	for(int i = 0; i < k; i++){
		cout << b[a[i]].soHieu << " - " << b[a[i]].ghe ;
		if(i < k-1) cout << " , ";
	}
	cout << "\n";
}

void A3(chuyenBay b[], int a[], int n, int k, int id, int pass, int &count){
	for(int i = pass; i < n; i++){
		a[id] = i;
		if(id == k-1){
			count ++;
			show(b, a, k, count);
		}else{
			A3(b, a, n, k, id + 1, i + 1, count);
		}
	}
}

int main(){
	int n = 7;
	chuyenBay b[7];
	init(b);
	A1(b, 0, n);
	
	chuyenBay cbMin = A2(b, 0, n-1);
	cout << "Chuyen bay co gia ve nho nhat la: \n";
	display(cbMin);
	
	int k = 4;
	int a[4] = {0};
	int count = 0;
	A3(b, a, n, k, 0, 0, count);
	return 0;
}
