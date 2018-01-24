#include <iostream>
#include <cctype>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int main() {
	ios::sync_with_stdio(false);
	string card;
	int t;
	cin >> t;
	REP(k, 1, t+1) {
		REP(i, 0, 52) { 
			cin >> card;
			if(i == 32) cout << "Case " << k <<  ": " << card << endl; 
		} 
	}
}