#include<bits/stdc++.h>
using namespace std;

void init(int a[12][12], int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = 0 + rand() % (5 - 0 + 1);
		}
	}
}

void display(int a[12][12], int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}
}

bool isValid(int x, int y, int n, int m, bool visited[12][12], int a[12][12]){
	return ((x >= 0) && (y >= 0) && x < n && y < m && !visited[x][y] && a[x][y] == 5);
}

void loang(int a[12][12], bool visited[12][12], int n, int m, int x, int y){
	visited[x][y] = true;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	
	for(int i = 0; i < 4; i++){
		int newX = x + dx[i];
		int newY = y + dy[i];
		if(isValid(newX, newY, n, m, visited, a)){
			loang(a, visited, n, m, newX, newY);
		}
	}
}

int count(int a[12][12], int n, int m){
	bool visited[12][12] = {false};
	int counted = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 5 && !visited[i][j]){
				counted++;
				loang(a, visited, n, m, i, j);
			}
		}
	}
	return counted;
}

int main(){
	int n = 12, m = 12;
	int a[12][12];
	init(a, n, m);
	cout << "Luoi: \n";
	display(a, n, m);
	
	cout << "so mien lien thong chua cac o co gia tri 5 tren luoi la: " << count(a, n, m);
	return 0;
}
