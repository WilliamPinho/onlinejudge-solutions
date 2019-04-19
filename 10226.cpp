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
  string s;
  getline(cin, s);
  getline(cin, s);
  cout.precision(4);
  while (t--) {
    map<string, int> m;
    double total = 0;
    while (getline(cin, s), !s.empty()) {
      total += 1;
      if (m.count(s)) {
        m[s]++;
      } else {
        m[s] = 1;
      }
    }
    for (auto& kv : m) {
      cout << kv.first << " " << fixed << (kv.second/total)*100 << endl;
    }
    if (t) cout << endl;
  }
}



