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
    int N, cur,prev;
    bool asc, desc;
    cin >> N;
    cout << "Lumberjacks:" << endl;
    rep(i,N) {
        asc = true;
        desc = true;
        cin >> prev;
        rep(j,9) {
            cin >> cur;
            if(cur < prev) asc = false;
            if(prev < cur) desc = false;
            prev = cur; 
        }
        if(asc || desc) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
	return 0;
}

