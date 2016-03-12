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
  int n, q, cur, pos;
  while(cin >> n >> q) {
    vector<vector<int>> adj(1000001);
    rep(i,n) {
      cin >> cur;
      adj[cur].push_back(i+1);
    }
    rep(i,q) {
      cin >> pos >> cur;
      cout << ((adj[cur].size() >= pos) ? adj[cur][pos-1] : 0) << endl; 
    }
  }
  return 0;
}

