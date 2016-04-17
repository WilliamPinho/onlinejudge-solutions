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

char update(char dir, char c) {
  if(c == 'D') {
    if(dir == 'N') return 'L'; 
    if(dir == 'O') return 'N'; 
    if(dir == 'S') return 'O'; 
    if(dir == 'L') return 'S'; 
  } else {
    if(dir == 'N') return 'O'; 
    if(dir == 'O') return 'S'; 
    if(dir == 'S') return 'L'; 
    if(dir == 'L') return 'N'; 
  }
}

int main() {
  int N, M, S;
  vector<string> grid;
  while(cin >> N >> M >> S) {
    if((N | M | S) ==  0) break;
    grid.assign(N,"");
    char c, dir;
    int u, v, u_, v_;
    rep(i,N) {
      rep(j,M) {
	cin >> c;
	grid[i].push_back(c);
	if(isalpha(c)) {
	  u = i, v = j;
	  dir = c;
	  grid[i][j] = '.';
	}
      }
    }
    string inst;
    cin >> inst;
    int count = 0;
    rep(i,inst.size()) {
      if(inst[i] == 'F') {
	u_ = max(min(N-1,u+(dir == 'N')*(-1) + (dir == 'S')),0);       
	v_ = max(min(M-1,v+(dir == 'O')*(-1) + (dir == 'L')),0);
	if(grid[u_][v_] != '#') u = u_, v = v_;
	if(grid[u][v] == '*') count++;
	grid[u][v] = '.';
      } else dir = update(dir,inst[i]);
    }
    cout << count << endl;
  }
  return 0;
}

