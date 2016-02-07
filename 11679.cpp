#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int B, N, deb, cred, val;
    int banks[30] = { 0 };
    bool possible;
    cin >> B >> N;
    while(B!=0 || N!=0) {
        possible = true;
        rep(i,B) {
            cin >> banks[i+1];
        }
        rep(i,N) {
            cin >> deb >> cred >> val;
            banks[deb] -= val;
            banks[cred] += val;
        }

        rep(i,B) {
            if(banks[i+1] < 0) {
                possible = false;
            }
        }
        if(possible) cout << "S" << endl;
        else cout << "N" << endl;
        cin >> B >> N;
        memset(banks, 0, sizeof(banks));
    }
	return 0;
}

