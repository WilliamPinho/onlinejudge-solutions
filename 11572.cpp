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
  cin >> t;
  while (t--) {
    int n, c = 0, len = 0, maxLen = 0;
    cin >> n;
    map<int,int> p; // last position
    REP(i, n) {
      cin >> c;
      len = p.count(c) ? min(len+1,i-p[c]) : len + 1;
      p[c] = i;
      maxLen = max(maxLen, len);
    }
    cout << maxLen << endl;
  }
}
