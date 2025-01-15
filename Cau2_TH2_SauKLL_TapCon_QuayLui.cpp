#include<bits/stdc++.h>
using namespace std;

void display(int a[], string s[], int k){
	for(int i = 0; i < k; i++){
		cout << s[a[i]];
		if( i < k-1) cout << " , ";
	}
	cout << "\n";
}
void Try(string s[], int a[], int n, int k, int id, int pass){
	for(int i = pass; i < n; i++ ){
		a[id] = i;
		if(id == k - 1){
			display(a, s, k);
		}else{
			Try(s, a, n, k, id + 1, i+1);
		}
	}
};


int main(){
	int n = 6;
	int k = 4;
	int a[6] = {0};
	string s1[6] = {"1", "2", "3", "4", "5", "6"};
	string s2[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
	cout << "Tat ca cac tap con " << k << " phan tu cua tap s la: \n";
	Try(s1, a, n, k, 0, 0);
	cout << "Tat ca cac cach lay ra " << k << " sinh vien tu " << n << " sinh vien la: \n";
	Try(s2, a, n, k, 0, 0); 
	return 0;
}
