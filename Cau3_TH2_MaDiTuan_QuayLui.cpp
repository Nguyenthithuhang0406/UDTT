#include<bits/stdc++.h>
using namespace std;

bool isValid(int H[20][20], int n, int x, int y){
	return (H[x][y] == 0 && x < n && x >= 0 && y < n && y >= 0);
}

void show(int H[20][20], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << H[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}
	cout << "\n";
}

void Try(int H[20][20], int a[], int b[],int k, int x, int y, int n, int &isSuccess){
	int i = 0;
	do{
		int newX = x + a[i];
		int newY = y + b[i];
		if(isValid(H, n, newX, newY)){
			H[newX][newY] = k;
			if(k == n * n){
				isSuccess = 1;
				show(H, n);
			}else{
				Try(H, a, b, k+1, newX, newY, n, isSuccess);
				if(!isSuccess) H[newX][newY] = 0;
			}
		}
		i++;
	}while(i < 8 && !isSuccess);
}

int main(){
	int n = 5;
	int a[8] = {2, 1, -1, -2, -2, -1, 1, 2} ;
	int b[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int H[20][20] = {0};
	int isSuccess = 0;
	
	H[0][0] = 1;
	Try(H, a, b, 2, 0, 0, n, isSuccess);
	if(isSuccess == 0) cout << "Khong tim thay duong di hop ly!";
	return 0;
}
