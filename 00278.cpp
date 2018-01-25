#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t, n, m;
	char piece;
	cin >> t;
	while(t--) {
		cin >> piece >> n >> m;
		if(m < n) swap(m, n);
		if(piece == 'Q' || piece == 'r') cout << n << endl;
		else if(piece == 'K') cout << ((n+1)>>1)*((m+1)>>1)  << endl;
		else cout << (n>>1)*m + (n&1)*((m+1)>>1) << endl;
	}
	return 0;
}