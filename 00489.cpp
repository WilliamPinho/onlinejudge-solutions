#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int round, wrongGuesses;
    set<char> word, guesses;
    while(cin >> round, round != -1) {
    	wrongGuesses = 0, word.clear(), guesses.clear();
        cout << "Round " << round << endl;
        string input;
        cin >> input;
        for(char c : input) word.insert(c);
        cin >> input;
        for(char c : input) {
        	if(guesses.insert(c).second && !word.erase(c))
        		wrongGuesses++;
        	if(wrongGuesses == 7 || word.empty()) break;
        }
        cout << (wrongGuesses == 7 ? "You lose." : (word.empty() ? "You win." : "You chickened out.")) << endl;
    } 
}
