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
    int T, N;
    int prev, cur, high, low;
    cin >> T;
    rep(i,T) {
        high = 0;
        low = 0;
        cin >> N;
        cin >> prev;
        rep(j,N-1) {
            cin >> cur;
            if(cur > prev) high++;
            else if(cur < prev) low++;
            prev = cur;
        }
        cout << "Case " << i+1 << ": " << high << ' ' << low << endl;
    }
	return 0;
}

