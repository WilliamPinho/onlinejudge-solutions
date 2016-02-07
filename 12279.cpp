#include <iostream>

using namespace std;

int main() {
    int n, t = 1, x, total = 0;
    cin >> n;
    while(n != 0) {
        cout << "Case " << t << ": ";
        for(int i = 0; i < n; ++i) {
            cin >> x;
            total += x > 0 ? 1 : -1;
        }
        cout << total << endl;
        t++;
        total = 0;
        cin >> n;
    }
}

