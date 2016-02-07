#include <iostream>

using namespace std;

int main() {
    int t = 1;
    string s;
    cin >> s;
    while(s != "*") {
        cout << "Case " << t << ": ";
        if(s == "Hajj") cout << "Hajj-e-Akbar" << endl;
        else if(s == "Umrah") cout << "Hajj-e-Asghar" << endl;
        t++;
        cin >> s;
    }
}
