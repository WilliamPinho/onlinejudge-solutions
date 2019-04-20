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
  int t, c;
  while (cin >> t, t) {
    priority_queue<long> pq;
    while (t--) {
      cin >> c;
      pq.push(-c); // trick to use max heap as min heap
    }
    long cost = 0, total = 0;
    while (true) {
      cost = pq.top(); pq.pop();
      if (pq.empty()) break;
      cost += pq.top(); pq.pop();
      total += cost;
      pq.push(cost);
    }
    cout << (total ? -total : 0) << endl;
  }
}
