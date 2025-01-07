#include<bits/stdc++.h>
using namespace std;

void insert_Sort(int a[], int n){
	int i, j;
	for(int i = 2; i <= n; i++){
		j = i - 1;
		int key = a[i];
		while(j >= 1 && key < a[j]){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 1; i <= n; i++) cin >> a[i];
	insert_Sort(a, n);
	return 0;
}

//Do phuc tap
//ham insert_Sort: 
//Vong lap for1: n-2
//vong lap while trong for1 ung voi moi lan i: 1+ 2 + .. + (n-1) = (n-1) * n / 2
//vong lap for3: n
//=> ham insert_Sort: O(n^2) + O(n) = O(n^2)
//Ham main: O(n) + O(n^2) = O(n^2)
