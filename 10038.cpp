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
  int n, cur, prev, diff;
  while(true) {
    cin >> n;
    if(cin.eof()) break;
    vector<bool> visited(n-1,false);
    bool jolly = true;
    cin >> cur;
    rep(i,n-1) {
      prev = cur;
      cin >> cur;
      diff = abs(cur-prev);
      if(diff > 0 && diff < n && !visited[diff-1]) visited[diff-1] = true;
      else jolly = false;
    }
    cout << (jolly ? "Jolly" : "Not jolly") << endl;
  }
  return 0;
}

