#include<bits/stdc++.h>
using namespace std;

void init(stack<int>& a){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a.push(x);
	}
}

void display(stack<int>& a){
    stack<int> temp = a; 
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void insertSort(stack<int>& a, int x){
	//neu ngan xep rong hoac phan tu tren dau nho hon phan tu muon chen vao thi push vao luon tren dinh stack
	if(a.empty() || a.top() <= x){
		a.push(x);
	}else{
		//luu tru phan tu dinh vao bien tam
		int tmp = a.top();
		a.pop();
		//de quy chen phan tu x vao
		insertSort(a, x);
		//sau khi chen xong thi dua phan tu truoc do da lay ra tro lai ngan xep
		a.push(tmp);
	}
}

void sortStack(stack<int>& a){
	//neu ngan xep khong rong
	if(!a.empty()){
		//lay ra phan tu tren dau ngan xep
		int x = a.top();
		a.pop();
		//goi de quy
		sortStack(a);
		//chen phan tu lay ra vao ngan xep
		insertSort(a, x);
	}
}
int main(){
	stack<int> a;
	init(a);
	sortStack(a);
	cout << "stack sau khi sap xep la: ";
	display(a);
	return 0;
}
