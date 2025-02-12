#include<bits/stdc++.h>
using namespace std;

string firstWord(string s){
	string tmp = "";
	int i = 0;
	int n = s.length() - 1;
	while(i <= n && s[i] != ' '){
		tmp += s[i];
		i++;
	}
	return tmp;
}

void z_algo(string s, int z[]){
	int n = s.length(), left = 0, right = 0;
	for(int i = 1; i < n; i++){
		if( i > right){
			left = right = i;
			while(right < n && s[right - left] == s[right]){
				right ++;
			}
			z[i] = right - left;
			right --;
		}else{
			if(z[i - left] < right - i + 1){
				z[i] = z[i - left];
			}else{
				left = i;
				while(right < n && s[right - left] == s[right]) {
					right ++;
				} 
				z[i] = right - left;
				right --;
			}
		}
	}
}

int count(string new_S, int n, int z[], string w){
	z_algo(new_S, z);
	int count = 0;
	int w_length = w.length();
	for(int i = 0; i < n; i++){
		if(z[i] == w_length) count ++;
	}
	return count;
}

int main(){
	string s = "hello world, hello everyone. hello again!";
	string w = firstWord(s);
	cout << "Tu dau tien trong doan van ban la: " << w << "\n";
	string new_S = w + "$" + s;
	int n = new_S.length();
	int z[n] = {0};
	cout << "Xau '" << w << "' xuat hien trong xau '" << s << "' " << count(new_S, n, z, w) << " lan\n";
	return 0;
}
