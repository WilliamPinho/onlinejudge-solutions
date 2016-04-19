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

int N, ans;
vi adj;
vector<bool> visited;
vi n_fwd;

int dfs(int u) {
  visited[u] = true;
  int v = adj[u];
  int total = 0;
  if(!visited[v]) total = 1 + dfs(v);
  visited[u] = false;
  return n_fwd[u] = total;
}

int main() {
  int T;
  cin >> T;
  rep(c,T) {
    cin >> N;
    n_fwd.assign(N,-1);
    ans = 0;
    adj.assign(N, -1);
    int u, v;
    visited.assign(N,false);
    rep(i,N) {
      cin >> u >> v;
      adj[u-1] = v-1;
    }
    for(int i = 0; i < N; ++i) {
      if(n_fwd[i] == -1)
	dfs(i);
    }
    int max_val = 0;
    rep(i,N) {
        if(max_val < n_fwd[i]) {
        max_val = n_fwd[i];
	ans = i;
      }
    }
    cout << "Case " << c+1 << ": " << ans+1 << endl;
  }
  return 0;
}

