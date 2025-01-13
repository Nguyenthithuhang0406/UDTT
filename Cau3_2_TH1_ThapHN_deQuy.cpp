#include<bits/stdc++.h>
using namespace std;

void F1(int n, char a, char b, char c){
	if( n == 1){
		cout << "Chuyen 1 dia tu cot " << a << " sang cot " << c << "\n";
	}else{
		F1(n-1, a, c, b);
		F1(1, a, b, c);
		F1(n-1, b, a, c);
	}
}

struct Call{
	int n;
	char a, b, c;
};
	
void F2(int n, char a, char b, char c){
	stack<Call> s;
	Call first_call = {n, a, b, c};
	s.push(first_call);
	
	while(!s.empty()){
		Call call = s.top();
		s.pop();
		if(call.n == 1){
			cout << "Chuyen 1 dia tu cot " << call.a << " sang cot " << call.c << "\n";
		}else{
			Call call_1 = {call.n - 1, call.a, call.c, call.b};
			Call call_2 = {1, call.a, call.b, call.c};
			Call call_3 = {call.n - 1, call.b, call.a, call.c};
			s.push(call_3);
			s.push(call_2);
			s.push(call_1);
		}
	}
}

int main(){
	int n = 3;
	cout << "Chuyen " << n << " dia: \n";
	F1(n, 'A', 'B', 'C');
	cout << "Khu de quy: \n";
	F2(n, 'A', 'B', 'C');
	return 0;
}
