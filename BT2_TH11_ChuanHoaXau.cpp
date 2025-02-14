#include<bits/stdc++.h>
using namespace std;

int count(string p, string target){
	int pos = 0;
	int cnt = 0;
	while((pos = p.find(target, pos)) != -1){
		cnt ++;
		pos += 5;
	}
	return cnt;
}

void replaceWord(string &p, string target, string r){
	int pos = 0;
	int length = target.length();
	int r_length = r.length();
	while((pos = p.find(target, pos)) != -1){
		p.replace(pos, length, r );
		pos += r_length;
	}
}

int main(){
	string p = "A child is playing in the park. Every child loves to play. The child laughed." ;
	cout << "So luong tu child trong van ban la: " << count(p, "child") << " tu .\n";
	string r = "children";
	replaceWord(p, "child", "children");
	cout << "Doan van sau khi thay the la: " << p ;
	return 0;
}
