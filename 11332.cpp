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

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int g(int n) {
    if(n/10 == 0) return n;
    int sum = 0;
    while(n != 0) {
        sum += n%10;
        n/=10;
    }
    return g(sum);
}

int main() {
    int n;
    cin >> n;
    while(n!=0) {
        cout << g(n) << endl;
        cin >> n;
    }
	return 0;
}

