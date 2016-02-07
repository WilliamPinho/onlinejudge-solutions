#include <iostream>
using namespace std;

int main() {
    int t, x, y, a, b;
    while(true) {
        cin >> t;
        if(t == 0) break;
        cin >> x >> y;
        while(t>0) {
            cin >> a >> b;
            if(a == x || b == y) cout << "divisa" << endl;
            else if(a < x) {
                if(b < y) cout << "SO" << endl;
                else cout << "NO" << endl;
            } else {
                if(b < y) cout << "SE" << endl;
                else cout << "NE" << endl;
            }
            t--;
        }
    }
}
