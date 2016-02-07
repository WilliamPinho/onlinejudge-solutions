#include <iostream>

using namespace std;

int main() {
    string line, text;
    while(getline(cin,line)) text += line + "\n";
    cout << text;
}
