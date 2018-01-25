#include <iostream>
#include <algorithm>

using namespace std;

inline int how_many_knights(int n, int m) {
	if(n > m) swap(n,m);
	if(n == 1) return m;
	else if(n == 2) return ((m>>2)<<2) + (m&3?(((m&3)==1)?2:4):0);
	return ((n*m+1)>>1);
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	while(cin >> n >> m, n || m)
		cout << how_many_knights(n,m) << " knights may be placed on a " << n << " row " << m << " column board." << endl;
	return 0;
}