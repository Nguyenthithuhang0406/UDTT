#include<bits/stdc++.h>
using namespace std;

void show(int a[], int n, string c[]){
	for(int i = 1; i <= n; i++){
		cout << c[a[i]] << " ";
	}
	cout << endl;
}
void Try(int k, int n, int a[], int dd[], string c[]){
	for(int i = 1; i <= n; i++){
		if(dd[i] == 0){
			a[k] = i;
			
			if(k == n){
				show(a, n, c);
			}else{
				dd[i] = 1;
				Try(k+1, n, a, dd, c);
				dd[i] = 0;
			}
		}
	}
}

int main(){
	int n = 6;
	int a[n + 1] = {0};
	int dd[n + 1] = {0};
	string s1[n+1] = {"0", "1", "2", "3", "4", "5", "6"};
	string s2[n+1] = {"0", "Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
	cout << "Tat ca cac hoan vi cua tap s la: \n";
	Try(1, n, a, dd, s1);
	cout << "Tat ca cac cach xep 6 sinh vien la: \n";
	Try(1, n, a, dd, s2);
	return 0;
}
