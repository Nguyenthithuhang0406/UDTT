#include<bits/stdc++.h>
using namespace std;

void sort(float m[], float k[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(m[j] < m[i]){
				swap(m[i], m[j]);
				swap(k[i], k[j]);
			}
		}
	}
}

float A6(float m[], float k[], int dd[], int n, float kt){
	sort(m, k, n);
	float sum = 0;
	int i = 0;
	while(kt > 0 && i < n){
		if(kt >= k[i]){
			sum += m[i];
			kt -= k[i];
			dd[i] = 1;
		}
		i++;
	}
	return sum;
}

void display(float m[], float k[], int dd[], int n){
	cout << "Danh sach goi hang duoc chon la: \n";
	for(int i = 0; i < n; i++){
		if(dd[i] == 1){
			cout << " { " << m[i] << " , " << k[i] << " }; ";
		}
	}
}
int main(){
	int n = 5;
	float m[n] = {1, 4, 2, 3, 5};
	float k[n] = {3.2, 10.3, 2, 8, 3};
	float kt = 20;
	int dd[n] = {0};
	cout << "Tong khoi luong toi thieu la: " << A6(m, k, dd, n, kt) << "\n";
	display(m, k, dd, n);
	return 0;
}
