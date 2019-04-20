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
  int t, op, n;
  while (cin  >> t) {
    bool isSt = true, isQ = true, isPq = true;
    priority_queue<int> pq;
    queue<int> q;
    vector<int> st;
    while (t--) {
      cin >> op >> n;
      if (op == 1) {
        pq.push(n);
        q.push(n);
        st.push_back(n);
      } else {
        if (pq.empty()) {
          isPq = isQ = isSt = false;
          continue;
        }
        isPq = isPq && (n == pq.top()); pq.pop();
        isQ = isQ && (n == q.front()); q.pop();
        isSt = isSt && (n == st.back()); st.pop_back();
      }

    }
    if (!isPq && !isQ && !isSt) cout << "impossible" << endl;
    else if (isPq && !isQ && !isSt) cout << "priority queue" << endl;
    else if (!isPq && isQ && !isSt) cout << "queue" << endl;
    else if (!isPq && !isQ && isSt) cout << "stack" << endl;
    else cout << "not sure" << endl; 
  }  
}
