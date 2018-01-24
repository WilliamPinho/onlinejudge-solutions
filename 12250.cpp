#include <iostream>

using namespace std;

int main() {
    int t = 1;
    string s;
    ios::sync_with_stdio(false);
    cin >> s;
    while(s != "#") {
        cout << "Case " << t << ": ";
        if(s == "HELLO") cout << "ENGLISH" << endl;
        else if(s == "HALLO") cout << "GERMAN" << endl;
        else if(s == "HOLA") cout << "SPANISH" << endl;
        else if(s == "BONJOUR") cout << "FRENCH" << endl;
        else if(s == "CIAO") cout << "ITALIAN" << endl;
        else if(s == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
        else cout << "UNKNOWN" << endl;
        cin >> s;
        t++;
    }
}

