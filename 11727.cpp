#include <iostream>

using namespace std;

int main() {
    int t, num[3], k;
    cin >> t;
    k = t;
    while(t>0) {
        cin >> num[0] >> num[1] >> num[2];
        if(num[0] < num[1]) swap(num[0],num[1]);
        if(num[1] < num[2]) swap(num[1],num[2]);
        if(num[0] < num[1]) swap(num[0],num[1]);
        cout << "Case " << k-t+1 << ": " << num[1] << endl;
        t--;
    }
}
