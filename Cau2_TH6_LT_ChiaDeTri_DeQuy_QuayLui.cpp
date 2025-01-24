#include<bits/stdc++.h>
using namespace std;

void show(string s[], int a[], int k, int count){
	cout << "Cach " << count << " : \n";
	for(int i = 0; i < k; i++){
		cout << s[a[i]] << " ";
	}
	cout << "\n";
}
void A4(string s[], int a[], int n, int k, int id, int pass, int &count){
	for(int i = pass; i < n; i++){
		a[id] = i;
			
		if( id == k-1){
			count ++;
			show(s, a, k, count);
		}else{
			A4(s, a, n, k, id+1, i+1, count);
		}
	}
}
int main(){
	string s[7] = {"A", "B", "C", "D", "E", "F", "G"};
	int a[6] = {0};
	int n = 7, k = 6, count = 0, id = 0, pass = 0;
	A4(s, a, n, k, id, pass, count);
	cout << "Co tat ca " << count << " cach!";
	return 0;
}
