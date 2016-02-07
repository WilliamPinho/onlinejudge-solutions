#include <iostream>

using namespace std;

int main() {
    int t, n, minPos, maxPos, x;
    cin >> t;
    while(t>0) {
        minPos = 100;
        maxPos = -1;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            if(x < minPos) minPos = x;
            if(x > maxPos) maxPos = x;
        }
        cout << 2*(maxPos - minPos) << endl;
        t--;
    }
}
