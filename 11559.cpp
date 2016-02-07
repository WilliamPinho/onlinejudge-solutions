#include <iostream>
#include <climits>
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
	int N, B, H, W, price, min_cost, avail, cost;
    while(!cin.eof()) {
        cin >> N >> B >> H >> W;
        min_cost = INT_MAX;
        rep(i,H) {
            cin >> price;
            rep(j,W) {
                cin >> avail;
                if(avail >= N) {
                    cost = N*price;
                    if(cost <= B) {
                        min_cost = min(min_cost,cost);
                    }
                }
            }
        }
        if(!cin.eof()) {
            if(min_cost == INT_MAX) cout << "stay home\n";
            else cout << min_cost << endl;
        }
    }
    return 0;
}

