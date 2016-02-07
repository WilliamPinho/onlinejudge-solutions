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
    int T, max_rank;
    cin >> T;
    int rank[10];
    string url[10];
    rep(i,T) {
        max_rank = INT_MIN; 
        rep(j,10) {
            cin >> url[j];
            cin >> rank[j];
            max_rank = max(max_rank,rank[j]);
        }
        cout << "Case #" << i+1 << ":\n";
        rep(j,10) {
            if(rank[j] == max_rank) {
                cout << url[j] << endl;
            }
        }
    }
	return 0;
}

