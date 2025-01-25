#include<bits/stdc++.h>
using namespace std;

void init(int a[], int n){
	for(int i = 0; i < n; i++){
		a[i] = rand() % 10000;
	}
}

void display(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

void quickSort(int t, int p, int a[]){
	if(t < p) {
		int i = t, j = p, chot = a[(t+p) / 2];
		while(i < j){
			while(a[i] < chot) i++;
			while(a[j] > chot) j--;
			if(i <= j){
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		quickSort(i,p, a);
		quickSort(t, j, a);
	}
}

void khuDeQuy(int a[], int n){
	//tao stack de luu chi so cua cac doan can sx
	int stack[n];
	int top = -1;
	
	//day doan (0, n-1) vao stack
	stack[++top] = 0;
	stack[++top] = n-1;
	
	//tiep tuc den khi stack rong
	while(top >= 0){
		//lay doan hien tai tu stack
		int p = stack[top--];
		int t = stack[top--];
		
		//chon phan tu chot
		int i = t, j = p, chot = a[(t+p)/2];
		
		//phan doan mang
		while(i <= j){
			while(a[i] < chot) i++;
			while(a[j] > chot) j--;
			if(i <= j){
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		
		//day cac doan con vao stack
		//doan ben trai
		if(t < j){
			stack[++top] = t;
			stack[++top] = j;
		}
		//doan ben phai
		if(i < p){
			stack[++top] = i;
			stack[++top] = p;
		}
	}
}
int main(){
	int n = 3000;
	int a[3000];
	init(a, n);
	quickSort(0, n-1, a);
//	khuDeQuy(a, n);
	cout << "Mang sau khi da sap xep la: \n";
	display(a, n);
	return 0;
}
