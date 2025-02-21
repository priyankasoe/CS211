#include <iostream>
#include <vector> 

// bisect the minimum max distances 
// given a minimum max distance, can we tell if it is possible with the
// given arrangements / available access points 

using namespace std; 

int can(long n_access_points, vector<long> * house_nums, double min_max_dist);

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; i++) {

        int n;
        int m;

        cin >> n >> m; 


        // populate list of house nums 
        vector<long> house_nums;
        long curr_house_num; 
        for (int i = 0; i < m; i++) {
            cin >> curr_house_num; 
            house_nums.push_back(curr_house_num);
        }

        sort(house_nums.begin(), house_nums.end());

        // the maximum min max distance is the difference between
        // the min and max house numbers divided by 2 (1 box)
        double r = (house_nums.front() + house_nums.back()) / 2.0;
        double l = 0.0; 

        double curr_dist = l + ((r-l) / 2);
        int possible = can(n, &house_nums, curr_dist); 

        for (int i = 0; i < 80; i++) {
            // decrease distance to see if we can obtain a smaller dist
            if (possible) {
                r = curr_dist; 
            }
            // increase distance because this one didn't work :( 
            else {
                l = curr_dist; 
            }

            curr_dist = l + ((r-l) / 2);
            possible = can(n, &house_nums, curr_dist); 
        }

        printf("%.1lf\n", curr_dist);
    }

    return 0;
}


// this will run in O(n) time where n is the length of the house_nums arr
// returns 0 if not possible, 1 if possible
int can(long n_access_points, vector<long> * house_nums, double min_max_dist) {
    long ap_count = 0; 
    double end_range = 0;
    
    vector<double> ap_locations; 

    double curr_house_num;

    for (int i = 0; i < (*house_nums).size(); i++) {
        curr_house_num = (*house_nums)[i];
        if (curr_house_num > end_range) {
            ap_locations.push_back(curr_house_num + min_max_dist); 
            end_range = curr_house_num + (2 * min_max_dist); 
            ap_count += 1; 
            if (ap_count > n_access_points) {
                return 0;
            }
        }
    }

    return 1;
}