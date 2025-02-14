#include<bits/stdc++.h>
using namespace std;

struct hoiThao{
	string chuDe;
	float thoiGianBD;
	float thoiGianKT;
};

void init(vector<hoiThao>& d){
	hoiThao ht1 = {"Tim kiem viec lam", 9, 10};
	hoiThao ht2 = {"Ky nang mem", 10, 12};
	hoiThao ht3 = {"Khoi nghiep", 13, 15};
	hoiThao ht4 = {"Ky nang viet email", 11, 12};
	hoiThao ht5 = {"Ky nang viet CV", 14, 16};
	d.push_back(ht1);
	d.push_back(ht2);
	d.push_back(ht3);
	d.push_back(ht4);
	d.push_back(ht5);
}

bool compareTo(hoiThao a, hoiThao b){
	return a.thoiGianKT < b.thoiGianKT;
}

int count(vector<hoiThao>& d, int n, int dd[]){
	sort(d.begin(), d.end(), compareTo);
	int cnt = 0;
	float last_finish = 0;
	for(int i = 0; i < n; i++){
		if(d[i].thoiGianBD >= last_finish){
			cnt ++;
			dd[i] = 1;
			last_finish = d[i].thoiGianKT;
		}
	}
	return cnt;
}

void display(hoiThao ht){
	cout << ht.chuDe << ", thoi gian bat dau: " << ht.thoiGianBD << ", thoi gian ket thuc: " << ht.thoiGianKT << "\n";
}

void solve(vector<hoiThao>& d, int n, int dd[]){
	int cnt = count(d, n, dd);
	cout << "Mot nguoi co the tham gia nhieu nhat " << cnt << " hoi thao. \n";
	cout << "Danh sach hoi thao co the tham gia: \n";
	for(int i = 0; i < n; i++){
		if(dd[i] == 1){
			display(d[i]);
		}
	}
}

int main(){
	int n = 5;
	vector<hoiThao> d;
	init(d);
	int dd[n] = {0};
	solve(d, n, dd);
	return 0;
}
