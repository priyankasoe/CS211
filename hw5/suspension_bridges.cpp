#include <iostream>
#include <vector>
#include <cmath> 
#include <climits>

using namespace std; 

double can(double a, double d, double s);

int main() {

    double d; 
    double s; 

    cin >> d >> s; 


    double l = 0; 

    // max a is ??? 
    // because this is the open rectangle bounding the length of the bridge 
    double r = 0.0 + LONG_MAX;

    double a = l + (r-l) / 2;
    double diff = can(a, d, s); 
    for (int i = 0; i < 100; i++) {
        // increase a because function is decreasing 
        if (diff >= 0) {
            l = a; 
        }
        else {
            r = a; 
        }
        a = l + (r-l) / 2;
        diff = can(a, d, s); 
    }

    // now calculate length based on a: 
    double len = 2 * a * sinh( (d / (2 * a)) );
    printf("%.6lf\n", len);

    return 0; 
}

double can(double a, double d, double s) {
    return (a * cosh( (d / (2 * a)) )) - a - s;
}
