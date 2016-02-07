#include <iostream>

using namespace std;

int main() {
    int x0, x1, x2, x3, answer;
    do {
        cin >> x0 >> x1 >> x2 >> x3;
        answer = 1080;
        answer += ((x0-x1) >= 0 ? (x0-x1)*9 : (x0-x1)*9 + 360);
        answer += ((x2-x1) >= 0 ? (x2-x1)*9 : (x2-x1)*9 + 360);
        answer += ((x2-x3) >= 0 ? (x2-x3)*9 : (x2-x3)*9 + 360);
        if(x0|x1|x2|x3 != 0) cout << answer << endl;
    } while(x0 | x1 | x2 | x3);
}
