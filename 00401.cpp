#include <iostream>
#include <map>

using namespace std;
map<char,char> mirror = {{'E','3'}, {'3','E'}, {'A','A'}, {'H','H'}, {'I','I'}, {'J','L'}, {'L','J'}, 
                         {'M','M'}, {'O','O'}, {'S','2'}, {'2','S'}, {'T','T'}, {'U','U'}, {'V','V'}, 
                         {'W','W'}, {'X','X'}, {'Y','Y'}, {'Z','5'}, {'5','Z'}, {'1','1'}, {'8','8'}};
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  string line;
  while(getline(cin, line)) {
    int i = 0, j = line.size()-1;
    bool isMirror = true, isPalind = true;
    while(i <= j) {
      char l = line[i], r = line[j];
      if(mirror.count(l) == 0 || mirror[l] != r) isMirror = false;
      if(l != r) isPalind = false;
      i++, j--;
    }
    cout << line << " -- is ";
    if(isPalind) cout << (isMirror ? "a mirrored palindrome." : "a regular palindrome.") << endl << endl;
    else cout << (isMirror ? "a mirrored string." : "not a palindrome.") << endl << endl;
  }
  return 0;
}
