#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    string line, text;
    bool first = true;
    while(getline(cin, line)) text += line + "\n";
    for(int i = 0; i < text.size(); ++i) {
        if(text[i] != '"') cout << text[i];
        else {
            cout << (first ? "``" : "''");
            first = first ? false : true;
        }
    }
}
