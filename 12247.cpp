#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int a[3], b[2];
	ios::sync_with_stdio(false);
	while(cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1]) {
		if(!a[0]) break;
		int candidate = 1;
		sort(a, a+3);
		sort(b, b+2);
		if(b[0]<a[1] && b[1] < a[2]) candidate = -1;
		else if(b[0] < a[1]) candidate = a[2]+1;
		else if(b[0] > a[1] && b[0] < a[2]) candidate = a[1]+1;
		bool isPossible = false;
		while(candidate < 53 && !isPossible) {
			isPossible = true;
			if(candidate == a[0] || candidate == a[1] || candidate == a[2] || candidate == b[0] || candidate == b[1]) 
				isPossible = false;
			if(!isPossible) candidate++;
		}
		cout << (candidate == 53 ? -1 : candidate) << endl;
	}
	return 0;
}