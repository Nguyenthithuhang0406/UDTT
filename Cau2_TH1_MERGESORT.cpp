#include<bits/stdc++.h>
using namespace std;

void display(float a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

void merge(float a[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	float a1[n1], a2[n2];
	for(int i = 0; i < n1; i++ ){
		a1[i] = a[left + i];
	}
	for(int i = 0; i < n2; i++ ){
		a2[i] = a[mid + i + 1];
	}
	
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if(a1[i] <= a2[j]){
			a[k] = a1[i];
			i++;
		}else{
			a[k] = a2[j];
			j++;
		}
		k++;
	}
	
	while( i < n1){
		a[k] = a1[i];
		i++;
		k++;
	}
	
	while(j < n2){
		a[k] = a2[j];
		j++;
		k++;
	}
}

void mergeSort(float a[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		
		merge(a, left, mid, right);
	}
}

int main(){
	int n = 15;
	float a[n] = {2.5, 1.4, 2.8, 9.2, 1.2, 4.3, 9.2, 3.5, 7.2, 13.2, 3.2, 14.4, 12.5, 2.1, 4.6};
	mergeSort(a, 0, n-1);
	cout << "Mang a sau khi sap xep la: \n";
	display(a, 15);
	return 0;
}
