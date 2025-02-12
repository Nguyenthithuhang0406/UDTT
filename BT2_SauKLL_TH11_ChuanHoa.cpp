#include<bits/stdc++.h>
using namespace std;

// Hàm xóa khoang trang thua o dau và cuoi
void trimSpaces(string &s) {
    while (!s.empty() && s.front() == ' ') s.erase(s.begin());
    while (!s.empty() && s.back() == ' ') s.pop_back();
}

// Hàm chu?n hóa van b?n
string normalizeText(string s) {
    trimSpaces(s); // Xóa khoang trang thua o dau và cuoi

    string result = "";
    bool capitalize = true; //xác dinh khi nào can viet hoa ký tu dau câu

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            // Neu khoang trang nam truoc dau cách hoac dau câu thì bo qua
            if (result.empty() || result.back() == ' ' )
                continue;
            result += ' ';
        } else if (s[i] == '.' || s[i] == ',') {
            // Xóa khoang trang truoc dau câu
            while (!result.empty() && result.back() == ' ') result.pop_back();
            result += s[i];

            // Ðam bao chi có mot dau cách sau dau câu (tru khi là ký tu cuoi cùng)
            if (i + 1 < s.length() && s[i + 1] != ' ') {
                result += ' ';
            }
            capitalize = (s[i] == '.'); // Sau dau cham thì viet hoa ký tu tiep theo
        } else {
            // Xu lý chu cái dau tiên cua câu
            if (capitalize && isalpha(s[i])) {
                result += toupper(s[i]);
                capitalize = false;
            } else {
                result += tolower(s[i]);
            }
        }
    }

    return result;
}

int main(){
	string s = "    hEllo,   my    name  is  John. i  am learning  c++  .   ";
	cout << "Doan van ban sau khi chuan hoa la: \n" << normalizeText(s);
	return 0;
}
