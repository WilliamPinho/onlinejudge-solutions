#include <iostream>

using namespace std;

int main() {
    int t, k, x;
    bool fits = true;
    cin >> t;
    k = t;
    while(t>0) {
        for(int i = 0; i < 3; ++i) {
            cin >> x;
            if(x > 20) fits = false;
        }
        cout << "Case " << k-t+1 << ": " << (fits ? "good" : "bad") << endl;
        fits = true;
        t--;
    }
}
