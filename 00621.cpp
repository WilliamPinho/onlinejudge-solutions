#include <iostream>

using namespace std;

int main() {
    int t, sz;
    string s;
    cin >> t;
    while(t>0) {
        cin >> s;
        sz = s.size();
        if(s == "1" || s == "4" || s == "78") cout << '+' << endl;
        else if(s[sz-2] == '3' && s[sz-1] == '5') cout << '-' << endl;
        else if(s[0] == '9' && s[sz-1] == '4') cout << '*' << endl;
        else  if(s[0] == '1' && s[1] == '9' && s[2] == '0') cout << '?' << endl;
        else cout << '+' << endl;
        t--;
    }
}
