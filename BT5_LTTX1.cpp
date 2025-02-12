#include<bits/stdc++.h>
using namespace std;

struct congViec{
	string maCV;
	string tgBD;
	float tg;
};

void init(vector<congViec>& c){
	congViec cv1 = {"CV01", "8:00", 15};
	congViec cv2 = {"CV02", "10:10", 20};
	congViec cv3 = {"CV03", "7:20", 45};
	congViec cv4 = {"CV04", "12:15", 5};
	congViec cv5 = {"CV05", "11:11", 30};
	congViec cv6 = {"CV06", "12:30", 13};
	c.push_back(cv1);
	c.push_back(cv2);
	c.push_back(cv3);
	c.push_back(cv4);
	c.push_back(cv5);
	c.push_back(cv6);
}

void view(congViec cv){
	cout << cv.maCV << " , thoi gian bat dau: " << cv.tgBD << " trong " << cv.tg << " phut" << "\n";
}

void display(vector<congViec> c, int n, int i){
	if(i < 0) return;
	view(c[i]);
	display(c, n, i-1);
}

void view2(vector<congViec> c, int tmp[], int k){
	for(int i = 0; i < k; i++){
		cout << c[tmp[i]].maCV;
		if(i < k-1) cout << " , ";
	}
	cout << "\n";
}

void taphopk(vector<congViec> c, int tmp[], int n, int k, int pass, int id){
	for(int i = pass; i < n; i++){
		tmp[id] = i;
		if(id == k - 1){
			view2(c, tmp, k);
		}else{
			taphopk(c, tmp, n, k, i+1, id+1);
		}
	}
}

void hoanvi(vector<congViec> c, int tmp2[],int dd[], int n, int id){
	for(int i = 0; i < n ; i++){
		if(dd[i] == 0){
			tmp2[id] = i;
			if(id == n-1) {
				view2(c, tmp2, n);
			}else{
				dd[i] = 1;
				hoanvi(c, tmp2, dd, n, id+1);
				dd[i] = 0;
			}
		}
	}
}
int main(){
	int n = 6;
	vector<congViec> c;
	init(c);
//	display(c, n, n-1);
//	int k = 5;
//	int tmp[5] = {0};
//	taphopk(c, tmp, n, k, 0, 0);
	
	int tmp2[6] = {0};
	int dd[6] = {0};
	hoanvi(c, tmp2, dd, n, 0);
	return 0;
}
