#include<bits/stdc++.h>
using namespace std;

//liet ke hoan vi

//dao gia tri hai phan tu
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

//hien thi mot cau hinh
void view_config(int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << x[i] ;
	}
	cout << endl;
}

//sinh cau hinh moi tu cau hinh dang co
void next_config(int x[], int n, int i){
	//tim phan tu dau tien nho nhat lon hon x[i]
	int k = n;
	while (x[k] < x[i]) i--;
	swap(x[k], x[i]);
	
	int j = n; i++;
	//dao nguoc doan x[i...n]
	while (i < j){
		swap(x[j], x[i]);
		i++;
		j--;
	}
}

//liet ke cac cau hinh
void listing_configs(int n){
	int i;
	int x[n+1] = {0};
	for(i = 0; i <= n; i++){
		x[i] = i;
	}
	do{
		view_config(x, n);
		i = n - 1;
		while(i > 0 && x[i] > x[i+1] ){
			i--;
		}
		next_config(x, n, i);
	}while (i > 0);
}

void init(){
	int n; cin >> n;
	listing_configs(n);
}

int main(){
	init();
	return 0;
}
