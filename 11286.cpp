#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <list>
#include <iterator>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


int main() {
  int t;
  while (cin >> t, t) {
    map<vector<int>, int> m;
    int maxV = 0, total = 0;
    while (t--) {
      vector<int> v(5);
      REP(i,5) cin >> v[i];
      sort(v.begin(), v.end());
      if (m.count(v)) {
        maxV = max(maxV, ++m[v]);
      } else {
        maxV = max(maxV, m[v] = 1);
      }
    }
    for (auto& p : m) 
      if (p.second == maxV) 
        total += maxV;
    cout << total << endl;
  }
}
