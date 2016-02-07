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
    int T, N, val_mile, val_juice;
    int call[20];
    cin >> T;
    rep(i,T) {
        val_mile = 0;
        val_juice = 0;
        cin >> N;
        rep(j,N) cin >> call[j];
        rep(j,N) val_mile += (call[j]/30 + 1)*10;
        rep(j,N) val_juice += (call[j]/60+ 1)*15;
        cout << "Case " << i+1 << ": ";
        if(val_mile <= val_juice) cout << "Mile ";
        if(val_mile >= val_juice) cout << "Juice ";
        cout << min(val_mile,val_juice) << endl;
    }
	return 0;
}

