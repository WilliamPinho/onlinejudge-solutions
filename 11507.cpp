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

void update(int *x, int *y, int *z, string cmd) {
  if(cmd == "No") { 
    return; 
  } else if(cmd == "+y") {
    if(*x!=0) {
      *y = *x;
      *x = 0;
    } else if(*y!=0) {
      *x = -(*y);
      *y = 0;
    }
  } else if(cmd == "-y") {
    if(*x!=0) {
      *y = -(*x);
      *x = 0;
    } else if(*y != 0) {
      *x = *y;
      *y = 0;
    }
  } else if(cmd == "+z") {
    if(*x!=0) {
      *z = *x;
      *x = 0;
    } else if(*z != 0) {
      *x = -(*z);
      *z = 0;
    }
  } else if(cmd == "-z") {
    if(*x!=0) {
      *z = -(*x);
      *x = 0;
    } else if(*z != 0) {
      *x = *z;
      *z = 0;
    }
  } 
}

int main() {
  int x, y, z;
  int L;
  string cmd;
  cin >> L;
  while(L != 0) {
    x = 1;
    y = 0;
    z = 0;
    for(int i = 0; i < L-1; ++ i) {
      cin >> cmd;
      update(&x,&y,&z,cmd);
    }
    if(x!=0) cout << (x == 1 ? "+x" : "-x") << endl; 
    if(y!=0) cout << (y == 1 ? "+y" : "-y") << endl; 
    if(z!=0) cout << (z == 1 ? "+z" : "-z") << endl;
    cin >> L;
  }
  return 0;
}

