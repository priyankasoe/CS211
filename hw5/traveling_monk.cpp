#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

double can(double time, vector<pair<double, double> > * ascend, vector<pair<double, double> > * descend);
double find_dist(double time, vector<pair<double, double> > * coords);

int main() {
    int a;
    int d; 

    cin >> a >> d; 
    vector<pair<double, double> > ascending; 
    vector<pair<double, double> > descending;

    double h; 
    double t; 

    double prev_h = 0; 
    double prev_t = 0; 

    ascending.push_back(make_pair(prev_t, prev_h));

    for (int i = 0; i < a; i++) {
        cin >> h >> t; 

        // cout << (prev_t + t) << ", " << (prev_h + h) << endl; 

        ascending.push_back(make_pair(prev_t + t, prev_h + h));
        prev_h += h;
        prev_t += t; 

    }

    // store height of mountain
    double time_ascend = prev_t; 

    // reset previous time to 0 for descending coords 
    // keep prev_h as is because that will be the height of the mountain 
    prev_t = 0; 

    descending.push_back(make_pair(prev_t, prev_h));

    for (int i = 0; i < d; i++) {
        cin >> h >> t; 
        // cout << (prev_t + t) << ", " << (prev_h - h) << endl; 
        descending.push_back(make_pair(prev_t + t, prev_h - h));
        prev_h -= h;
        prev_t += t; 
    }

    double time_descend = prev_t; 

    // precision
    double epsilon = 1e-9;
    double r = min(time_ascend, time_descend); 
    double l = 0.0; 

    double curr_time = l + ((r-l) / 2); 

    // diff is a(t) - d(t) => place in mountain while ascending - place in mountain while descending 
    double diff = can(curr_time, &ascending, &descending);

    // cout << "curr time: " << curr_time << endl; 
    // cout << "diff: " << diff << endl;

    // while the difference is greater than 10^-5
    for (int i = 0; i < 50; i++) {
        // if diff > 0 -> monk is higher in asending, so need to bisect lower time half 
        // move r pointer 
        if (diff >= 0) {
            r = curr_time; 
        }
        
        // diff < 0, so monk is higher in descending path, need to bisect upper time half 
        if (diff < 0) {
            l = curr_time; 
        }

        curr_time = l + (r-l) / 2; 
        // cout << "curr time: " << curr_time << endl; 
        // cout << "diff: " << diff << endl;
        diff = can(curr_time, &ascending, &descending); 
    }
    // while ( abs(diff) > epsilon) {

    //     // if diff > 0 -> monk is higher in asending, so need to bisect lower time half 
    //     // move r pointer 
    //     if (diff > 0) {
    //         r = curr_time; 
    //     }
        
    //     // diff < 0, so monk is higher in descending path, need to bisect upper time half 
    //     if (diff < 0) {
    //         l = curr_time; 
    //     }

    //     curr_time = l + (r-l) / 2; 
    //     // cout << "curr time: " << curr_time << endl; 
    //     // cout << "diff: " << diff << endl;
    //     diff = can(curr_time, &ascending, &descending); 
    // }


    printf("%.6lf\n", curr_time);

    return 0; 
}


double can(double time, vector<pair<double, double> > * ascend, vector<pair<double, double> > * descend) {

    pair<double, double> curr; 
    pair<double, double> next; 

    double a_t = find_dist(time, ascend); 
    double d_t = find_dist(time, descend); 

    return (a_t - d_t); 

}

// this will run in O(n) time where n is max(a, d); a - len(ascend), d - len(descend)

double find_dist(double time, vector<pair<double, double> > * coords) {

    pair<double, double> curr; 
    pair<double, double> next; 

    double dist; 

    for (int i = 0; i < (*coords).size() - 1; i++) {
        // find the coordinates that t is between [ curr, next )

        curr = (*coords)[i];
        next = (*coords)[i+1]; 
        
        if (curr.first <= time && next.first > time) {
            // calculate slope of line 
            double slope = (curr.second - next.second ) / (curr.first - next.first);
            // a(t) = y1 + m(time - x1) 
            dist = curr.second + slope * (time - curr.first); 
            return dist; 
        }
       
    }

    // handle edge case: coords(t) = height of mountain
    return (*coords)[(*coords).size()-1].second; 
}