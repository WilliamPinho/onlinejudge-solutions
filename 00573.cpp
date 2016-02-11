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
  double H, U, D, F, fatigue, position;
  int day;
  while(true) {
    cin >> H >> U >> D >> F;
    if (H == 0) break;
    position = 0;
    day = 1;
    fatigue = (F/100.0);
    while(true) {
      position += max(0.0, U*(1-(day-1)*fatigue));
      if(position > H) {
	cout << "success on day " << day << endl;
	break;
      }
      position -= D;
      if(position < 0) {
	cout << "failure on day " << day << endl;
	break;
      }
      day++;
    }
  }
  return 0;
}

