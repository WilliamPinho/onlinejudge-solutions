#include <iostream>

using namespace std;

int main() {
    int t, x, y;
    cin >> t;
    while(t>0) {
        cin >> x >> y;
        cout << (x/3)*(y/3) << endl;
        t--;
    }
}
