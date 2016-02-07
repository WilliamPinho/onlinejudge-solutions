#include <iostream>

using namespace std;

int main() {
    long long t, k, sz, animals, env_friend, total;
    cin >> t;
    while(t > 0) {
        cin >> k;
        total = 0;
        while(k > 0) {
            cin >> sz >> animals >> env_friend;
            total += sz*env_friend;
            k--;
        }
        cout << total << endl;
        t--;
    }
}
