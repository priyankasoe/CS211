#include <iostream>
#include <math.h> 

using namespace std; 

int main() {
    int t; 
    cin >> t; 

    // scan through t lines 
    double p, r, f; 
    long long a,b,c;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c; 
        p = a + 0.0;
        r = b + 0.0;
        f = c + 0.0;

        //double division = (double) f/p; 
        //double years = ((log10f(f) - log10f(p)) / log10f(r)) + 1.0;
        long years = 0; 
        while (p <= f) {
            p *= r; 
            years++; 
        }

        if (years < 0) {
            cout << 0; 
        } else {
            cout << (long long) years; 
        }

        cout << endl; 
    } 
}

