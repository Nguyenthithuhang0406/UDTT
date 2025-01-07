#include<bits/stdc++.h>
using namespace std;

void selection_Sort(int a[], int n){
	for(int i = 1; i < n; i++){
		int min = i;
		int j;
		for(int j = i+1; j <= n; j++){
			if(a[j] < a[min]) min = j;
		}
		swap(a[i], a[min]);
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
	selection_Sort(a, n);
	return 0;
}

//Do phuc tap
//ham selection_Sort: 
//Vong lap for1: n-1
//vong lap for2 trong for1 ung voi moi lan i: (n-1) + (n-2) +... + 1 = (n-1) * n / 2
//vong lap for3: n
//=> ham selection_Sort: O(n^2) + O(n) = O(n^2)
//Ham main: O(n) + O(n^2) = O(n^2)
