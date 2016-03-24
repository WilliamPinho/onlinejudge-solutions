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

bool isNeig(int u, int v, vector<vector<int>>& areas) {
  rep(j,areas[u].size()) {
    if(areas[u][j] == v) return true;
  }
  return false;
}

void woke_up_neig(int u, vector<vector<int>>& areas, vector<int>& count_woke, vector<bool>& wokenup) {
  rep(i,areas[u].size()) {
    int v = areas[u][i];
    
    if(!wokenup[v]) count_woke[v]++;
    if(count_woke[v] >= 3 && !wokenup[v]) {
      wokenup[v] = true;
      woke_up_neig(v, areas, count_woke, wokenup);
    }
  }
}

int main() {
  int N, M;
  while(cin >> N >> M) {
    vector<vector<int>> areas(26);
    set<int> awake;
    string line;
    cin >> line;
    rep(i,3) awake.emplace(line[i] - 'A');
    rep(i,M) {
      cin >> line;
      int u = line[0] - 'A';
      int v = line[1] - 'A';
      areas[u].push_back(v);
      areas[v].push_back(u);
    }
    int n_years = 0;
    bool willWakeUp = true;
    while(awake.size() < N) {
      set<int> woken_up;
      rep(u,26) {
	int connec_awake_areas = 0;
	rep(i,areas[u].size()) 
	  connec_awake_areas += awake.count(areas[u][i]);
	if(connec_awake_areas >= 3 && awake.count(u) <= 0) 
	  woken_up.emplace(u);
      }
      if(woken_up.empty()) {
	cout << "THIS BRAIN NEVER WAKES UP" << endl;
	willWakeUp = false;
	break;
      }
      for(auto u : woken_up)
	awake.emplace(u);
      n_years++;
    }
    if(willWakeUp)
      cout << "WAKE UP IN, " << n_years << ", YEARS" << endl;
  }
  return 0;
}

