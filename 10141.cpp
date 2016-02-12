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
#include <cfloat>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int n_req, n_prop, met_req, best_met_req, j = 1;
  double value, best_value;
  string proposal, garbage, best_proposal;
  while(cin >> n_req >> n_prop, n_req || n_prop) {
    best_value = DBL_MAX;
    best_met_req = -1;
    if(j != 1 && n_req != 0) cout << endl; 
            
    for(int i = 0; i < n_req; ++i) { 
      cin.ignore(); 
      getline(cin, garbage); 
    }
    for(int i = 0; i < n_prop; ++i) {
      getline(cin,proposal);
      scanf("%lf %d\n", &value, &met_req);
      if((met_req > best_met_req) || (met_req == best_met_req && best_value > value)) {
	best_proposal = proposal;
	best_met_req = met_req;
	best_value = value;
      }
      for(int k = 0; k < met_req; ++k) { getline(cin, garbage); }
    }
    cout << "RFP #" << j << endl;
    cout << best_proposal << endl;
    j++;
  }
  return 0;
}

