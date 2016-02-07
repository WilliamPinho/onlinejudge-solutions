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
#include <climits>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int T, N, max_val, cur;
    cin >> T;
    rep(i,T) {
        max_val = INT_MIN;
        cin >> N;
        rep(j,N) {
            cin >> cur;
            max_val = max(max_val,cur);
        }
        cout << "Case " << i+1 << ": " << max_val << endl;
    }
	return 0;
}

