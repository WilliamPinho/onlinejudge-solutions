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
  int m, n, n_elem, cur;
  while(cin >> m >> n) {
    vector<vii> adj(n,vii(0));
    deque<int> line;
    int t = m;
    while(t > 0) {
      cin >> n_elem;
      if(n_elem != 0) {
	while(n_elem>0) {
	  cin >> cur;
	  line.push_back(cur);
	  n_elem--;
	}
	while(!line.empty()) {
	  cin >> cur;
	  adj[line.front()-1].push_back(make_pair(cur,m-t+1));
	  line.pop_front();
	}
      }
      t--;
    }
    cout << n << " " << m << endl;
    for(int i = 0; i < n; ++i) {
      cout << adj[i].size();
      for(int j = 0; j < adj[i].size(); ++j) {
	cout << " " << adj[i][j].second;
      }
      cout << endl;
      for(int j = 0; j < adj[i].size(); ++j) {
	if(j != 0) cout << " ";
	cout << adj[i][j].first;
      }
      cout << endl;
    }
  }
  return 0;
}

