#include <iostream>

using namespace std;

int main() {
    int n, k, a, b, gap;
    bool diff;
    cin >> n;
    while(n>0) {
        diff = false;
        cin >> k;
        cin >> a >> b;
        gap = a-b;
        k--;
        while(k>0) {
            cin >> a >> b;
            if(a-b != gap)
                diff = true;
            k--;
        }
        if(diff) cout << "no" << endl;
        else cout << "yes" << endl;
        if(n!=1) cout << endl;
        n--;
    }
    return 0;
}
