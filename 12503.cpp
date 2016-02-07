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
    int T, N, p, pos;
    int instruc[100];
    string s;
    cin >> T;
    rep(i,T) {
        p = 0;
        cin >> N;
        rep(j,N) {  
            cin >> s;   
            if(s == "LEFT") {
                p--;      
                instruc[j] = -1;
            } else if(s == "RIGHT") {
                p++;
                instruc[j] = 1;
            } else if(s == "SAME") {
                cin >> s;
                cin >> pos;
                instruc[j] = instruc[pos-1];
                p += instruc[j]; 
            }
        }
        cout << p << endl;
    }
	return 0;
}

