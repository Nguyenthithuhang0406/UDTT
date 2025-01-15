#include<bits/stdc++.h>
using namespace std;

bool isValid(int H[9][9], int n, int x, int y) {
    for (int i = 1; i <= n; i++) {
        if (H[i][y] != 0 || H[x][i] != 0) return false; 
        if (x - i >= 1 && y - i >= 1 && H[x - i][y - i] != 0) return false; 
        if (x - i >= 1 && y + i <= n && H[x - i][y + i] != 0) return false;  
        if (x + i <= n && y - i >= 1 && H[x + i][y - i] != 0) return false; 
        if (x + i <= n && y + i <= n && H[x + i][y + i] != 0) return false;  
    }
    return true;
}

void show(int H[9][9], int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << H[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}
	cout << "\n";
}

void Try(int H[9][9], int k, int n, int &isSuccess){
	int i = 1;
	do{
		if(isValid(H, n, i, k)){
			H[i][k] = k;
			if(k == n){
				show(H, n);
				isSuccess = 1;
			}else{
				Try(H, k+1, n, isSuccess);
				if(!isSuccess) H[i][k] = 0;
			}
		}
		i++;
	}while(!isSuccess && i <= 8);
}

int main(){
	int n = 8;
	int H[9][9] = {0};
	int isSuccess = 0;
	Try(H, 1, n, isSuccess);
	if(isSuccess == 0) cout << "Khong tim thay duong di hop ly!";
	return 0;
}
