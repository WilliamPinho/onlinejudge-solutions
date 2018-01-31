#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
  string line;
  while(getline(cin,line), line != "DONE") {
    int i = 0, j = line.size()-1;
    bool isPalindrome = true;
    while(i < j && isPalindrome) {
      while(i < j && !isalpha(line[i])) i++;
      while(i < j && !isalpha(line[j])) j--;
      if(j <= i) break;
      if(tolower(line[i]) != tolower(line[j])) isPalindrome = false;
      i++, j--; 
    }
    cout << (isPalindrome ? "You won't be eaten!" : "Uh oh..") << endl;
  }
  return 0;
}
