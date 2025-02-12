#include<bits/stdc++.h>
using namespace std;

// H�m x�a khoang trang thua o dau v� cuoi
void trimSpaces(string &s) {
    while (!s.empty() && s.front() == ' ') s.erase(s.begin());
    while (!s.empty() && s.back() == ' ') s.pop_back();
}

// H�m chu?n h�a van b?n
string normalizeText(string s) {
    trimSpaces(s); // X�a khoang trang thua o dau v� cuoi

    string result = "";
    bool capitalize = true; //x�c dinh khi n�o can viet hoa k� tu dau c�u

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            // Neu khoang trang nam truoc dau c�ch hoac dau c�u th� bo qua
            if (result.empty() || result.back() == ' ' )
                continue;
            result += ' ';
        } else if (s[i] == '.' || s[i] == ',') {
            // X�a khoang trang truoc dau c�u
            while (!result.empty() && result.back() == ' ') result.pop_back();
            result += s[i];

            // �am bao chi c� mot dau c�ch sau dau c�u (tru khi l� k� tu cuoi c�ng)
            if (i + 1 < s.length() && s[i + 1] != ' ') {
                result += ' ';
            }
            capitalize = (s[i] == '.'); // Sau dau cham th� viet hoa k� tu tiep theo
        } else {
            // Xu l� chu c�i dau ti�n cua c�u
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
