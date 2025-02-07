#include <iostream>
using namespace std;

int main() {
    long days;
    cin >> days;

    long prev = -1;
    long curr = 0;

    long curr_money = 100;
    long curr_shares = 0;

    for (long i = 0; i < days; i++) {
        if (i == 0) {
            cin >> prev;
            continue;
        }

        cin >> curr;

        // buy and if we can buy any 
        if (prev < curr && curr_shares ==0) {
            if ((curr_money / prev) > 100000) {
                curr_shares = 100000;
                curr_money -= prev * 100000;
               
            } else {
                curr_shares = curr_money / prev;
                curr_money -= curr_shares * prev;
            }
        } else {
            // sell
            if (curr_shares != 0 && curr < prev) {
                curr_money += prev * curr_shares;
                curr_shares = 0;
            }
        }

        //cout << "curr_shares " << curr_shares << endl;

        prev = curr;
    }

    curr_money += curr_shares * prev;
    cout << curr_money << endl;

    return 0;
}
