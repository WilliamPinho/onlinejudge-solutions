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

vector<vi> grid;
vector<vector<bool>> visited;
enum type_cell { WATER = -1 };
int even, odd, T, R, C, M, N, W, wx, wy;;

bool isValid(int u, int v) {
  return u < R && u > -1 && v < C && v > -1 && grid[u][v] != WATER;
}

void dfs(int u, int v) {
  visited[u][v] = true;
  if(isValid(u+M,v+N)) {
    if(!visited[u+M][v+N]) 
       dfs(u+M,v+N);
    grid[u][v]++;
  }
  if(N != 0 && isValid(u+M,v-N)) {
    if(!visited[u+M][v-N]) 
       dfs(u+M,v-N);
    grid[u][v]++;
  }
  if(M != 0 && isValid(u-M,v+N)) {
    if(!visited[u-M][v+N]) 
       dfs(u-M,v+N);
    grid[u][v]++;
  }
  if(M != 0 && N != 0 && isValid(u-M,v-N)) {
    if(!visited[u-M][v-N]) 
       dfs(u-M,v-N);
    grid[u][v]++;
  }
  if(M != N) {
    swap(M,N);
    if(isValid(u+M,v+N)) {
      if(!visited[u+M][v+N]) 
	dfs(u+M,v+N);
      grid[u][v]++;
    }
    if(N != 0 && isValid(u+M,v-N)) {
      if(!visited[u+M][v-N]) 
	dfs(u+M,v-N);
      grid[u][v]++;
    }
    if(M != 0 && isValid(u-M,v+N)) {
      if(!visited[u-M][v+N]) 
	dfs(u-M,v+N);
      grid[u][v]++;
    }
    if(M != 0 && N != 0 && isValid(u-M,v-N)) {
      if(!visited[u-M][v-N]) 
	dfs(u-M,v-N);
      grid[u][v]++;
    }
    swap(M,N);
  }
  if(grid[u][v]%2 == 0) even++;
  else odd++;
}

int main() {
  cin >> T;
  rep(c, T) {
    cout << "Case " << c + 1 << ": ";
    cin >> R >> C >> M >> N >> W;
    grid.assign(R, vector<int> (C,0));
    visited.assign(R, vector<bool> (C,false));
    even = 0, odd = 0;
    rep(i, W) {
      cin >> wx >> wy;
      grid[wx][wy] = WATER;
    }
    dfs(0,0);
    cout << even << " " << odd << endl;
  }
  return 0;
}

