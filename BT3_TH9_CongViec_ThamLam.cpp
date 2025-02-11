#include<bits/stdc++.h>
using namespace std;

void sort(float s[], float f[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(f[j] < f[i]){
				swap(f[i], f[j]);
				swap(s[i], s[j]);
			}
		}
	}
}

void A3(float s[], float f[], int dd[], int n){
	sort(s, f, n);
	float last_finish = 0;
	for(int i = 0; i < n; i++){
		if(s[i] >= last_finish){
			dd[i] = 1;
			last_finish = f[i];
		}
	}
}

void display(float s[], float f[], int dd[], int n){
	for(int i = 0; i < n; i++){
		if( dd[i] == 1){
			cout << "{ " << s[i] << " , " << f[i] << " }; "; 
		}
	}
}

int main(){
	int n = 5;
	float s[n] = {8, 9, 10, 11, 12};
	float f[n] = {8.5, 11, 11.5, 12.5, 13};
	int dd[5] = {0};
	A3(s, f, dd, n);
	display(s, f, dd, n);
	return 0;
}
