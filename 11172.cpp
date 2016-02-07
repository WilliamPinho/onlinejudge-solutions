#include <iostream>

using namespace std;

int main() {
    long long x, y;
    int t;
    cin >> t;
    while(t>0) {
        cin >> x >> y;
        cout << (x < y ? "<" : (x > y ? ">" : "=")) << endl;
        t--;
    }
}
