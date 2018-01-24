#include <iostream>
#include <sstream>

using namespace std;

inline int getSuit(char suit) {
	switch(suit) {
		case 'S': return 0;
		case 'H': return 1;
		case 'D': return 2;
		case 'C': return 3;
	}
	return 0;
}

inline int cardVal(char card) {
	switch(card) {
		case 'A': return 4;
		case 'K': return 3;
		case 'Q': return 2;
		case 'J': return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	while(!cin.eof()) {
		string hand[13];
		int suitCount[4] = {0, 0, 0, 0};
		bool suitStopped[4] = {false, false, false, false};
		int handVal = 0, ignoringRulesHandVal;
		string card;
		// Read cards, add card points
		for(int i = 0; i < 13; ++i) {
			cin >> hand[i];
			suitCount[getSuit(hand[i][1])]++;
			handVal += cardVal(hand[i][0]);
		}

		// Subtract points for kings, queens and jacks
		for(int i = 0; i < 13; ++i) {
			int suit = getSuit(hand[i][1]);
			if(hand[i][0] == 'K' && suitCount[suit] < 2) handVal--;
			if(hand[i][0] == 'Q' && suitCount[suit] < 3) handVal--;
			if(hand[i][0] == 'J' && suitCount[suit] < 4) handVal--;
		}

		ignoringRulesHandVal = handVal;

		// Add points for suits
		for(int i = 0; i < 4; ++i) {
			if(suitCount[i] == 2) handVal++;
			if(suitCount[i] < 2) handVal+=2;
		}

		// Check stopped
		for(int i = 0; i < 13; ++i) {
			char rank = hand[i][0];
			int suit = getSuit(hand[i][1]);
			if(rank == 'A') suitStopped[suit] = true;
			else if (rank == 'K' && suitCount[suit] > 1) suitStopped[suit] = true;
			else if (rank == 'Q' && suitCount[suit] > 2) suitStopped[suit] = true;
		}

		// Decide strategy
		if (handVal < 14) cout << "PASS";
		else if (ignoringRulesHandVal > 15 && suitStopped[0] && suitStopped[1] && suitStopped[2] && suitStopped[3]) {
			cout << "BID NO-TRUMP";
		} else {
			cout << "BID ";
			int max_i;
			int max = 0;
			for(int i = 0; i < 4; ++i) {
				if(max < suitCount[i]) {
					max = suitCount[i];
					max_i = i;
				}
			}
			string s("SHDC");
			cout << s[max_i];
		}
		if(!cin.eof()) cout << endl;
	}
}