#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> deprecRec;
    int nMonths, month, nRec;
    double carVal, loanAmount, downPay, percentage;
    cin >> nMonths;
    while(nMonths > -1) {
        cin >> downPay >> loanAmount >> nRec;
        deprecRec.clear();
        deprecRec.resize(nMonths+1, 0.0);
        while(nRec > 0) {
            cin >> month >> percentage;
            deprecRec[month] = percentage;
            nRec--;
        }
        for(int i = 0; i < deprecRec.size(); ++i) {
            if(i > 0 && deprecRec[i] == 0) deprecRec[i] = deprecRec[i-1];
        }
        carVal = downPay + loanAmount;
        downPay = loanAmount/nMonths;
        int k;
        for(k = 0; k < nMonths; ++k) {
            carVal *= 1-deprecRec[k];
            if(carVal > loanAmount) {
                break;
            }
            loanAmount -= downPay;
        }
        cout << k << (k == 1 ? " month" : " months") << endl;
        cin >> nMonths;
    }
}
