#include<bits/stdc++.h>
using namespace std;

//liet ke cac tap con k phan tu
void next_config(int x[], int n, int i){
	x[i] += 1;
	i++;
	while(i <= n){
		x[i] = x[i-1] + 1;
		i++;
	}
}

//hien thi mot cau hinh
void view_config(int x[], int k){
	for(int i = 1; i <= k; i++){
		cout << x[i];
	}
	cout << "\n";
}

//liet ke cau hinh
void listing_configs(int k, int n){
	int i;
	int x[k+1] = {0};
	//cau hinh dau
	for(int i = 1; i <= k; i++){
		x[i] = i;
	}
	do{
		view_config(x, k);
		i = k;
		while(i > 0 && x[i] == n-k+i){
			i--;
		}
		next_config(x, n, i);
	}while (i > 0);
}

void init(){
 int n,k;
 cin >> n >> k;
 listing_configs(k, n);	
}

int main(){
	init();
	return 0;
}
