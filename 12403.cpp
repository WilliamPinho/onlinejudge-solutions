#include <iostream>

using namespace std;

int main() {
    int t, x, total = 0;
    string s;
    cin >> t;
    while(t>0) {
        cin >> s;
        if(s == "donate") {
            cin >> x;
            total += x;
        }
        if(s == "report") cout << total << endl;
        t--;
    }
}
