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
#include <iomanip>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int N, K, M;
  double total;
  double price[256];
  string line;
  unsigned char c;
  cin >> N;
  while(N>0) {
    total = 0;
    memset(price,0,256*sizeof(int));
    cin >> K;
    rep(i,K) {
      cin >> c;
      cin >> price[(int)c];
    }
    cin >> M;
    cin.ignore();
    while(M>0) {
      getline(cin,line);
      rep(i,line.size()) {
	total += price[(int)line[i]];
      }
      M--;
    }
    total /= 100;
    printf("%0.2f$\n", total);
    N--;
  }
  return 0;
}

