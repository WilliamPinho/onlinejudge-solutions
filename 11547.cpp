#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t, x;
    cin >> t;
    while(t>0) {
        cin >> x;
        cout << abs((((((x*567)/9+7492)*235)/47 - 498)/10)%10) << endl;
        t--;
    }
}
