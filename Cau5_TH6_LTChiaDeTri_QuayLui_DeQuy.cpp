#include<bits/stdc++.h>
using namespace std;

struct congViec{
	string maCV;
	string tgBD;
	int tgCan;
};

void init(vector<congViec>& c){
	congViec cv1 = {"cv01", "8:00", 60};
	congViec cv2 = {"cv02", "7:00", 30};
	congViec cv3 = {"cv03", "12:00", 45};
	congViec cv4 = {"cv04", "6:00", 120};
	congViec cv5 = {"cv05", "8:45", 15};
	congViec cv6 = {"cv06", "10:20", 60};
	
	c.push_back(cv1);
	c.push_back(cv2);
	c.push_back(cv3);
	c.push_back(cv4);
	c.push_back(cv5);
	c.push_back(cv6);
}

void display(congViec cv){
	cout << cv.maCV << " , thoi gian bat dau " << cv.tgBD << " trong " << cv.tgCan << "\n";
}

void A1(vector<congViec> c, int index){
	if(index < 0) return;
	display(c[index]);
	A1(c, index - 1);
}

int A2(vector<congViec> c, int l, int r){
	if(l > r) return 0;
	if(l == r){
		if(c[l].tgCan <= 30) return 1;
		else return 0;
	}
	int mid = (l + r) / 2;
	int countL = A2(c, l, mid);
	int countR = A2(c, mid+1, r);
	return countL + countR;
}

void show(vector<congViec> c, string L[], int tmp[], int n){
	for(int i = 0; i < n; i++){
		cout << L[i] << " - " << c[tmp[i]].maCV;
		if(i < n-1) cout << " , ";
	}
	cout << "\n";
}

void A3(string L[], vector<congViec> c, int tmp[], int dd[], int n, int k){
	for(int i = 0; i < n; i++){
		if(dd[i] == 0){
			tmp[k] = i;
			
			if(k == n-1){
				show(c, L, tmp, n);
			}else{
				dd[i] = 1;
				A3(L, c, tmp, dd, n, k+1);
				dd[i] = 0;
			}
		}
	}
}
int main(){
	int n = 6;
	vector<congViec> c;
	string L[6] = {"Huong", "Hang", "Phuong", "Trang", "Ninh", "Nga"};
	int tmp[6] = {0};
	int dd[6] = {0};
	init(c);
	A1(c, n-1);
	cout << "So cong viec co thoi gian thuc hien khong qua 30 phut la: " << A2(c, 0, n-1);
	A3(L, c, tmp, dd, n, 0);
	return 0;
}
