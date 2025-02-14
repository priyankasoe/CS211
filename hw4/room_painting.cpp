#include <iostream> 
#include <vector> 
#include <cmath>

using namespace std; 

// logic: 
// sort paint can sizes offered array \ in O(nlogn) 
// for each desired paint can size Joe needs: 
//    modified binary search through offered array 
//    until finding the minimum size that satisifes his desire 
//    calculate the difference and add to paint wasted 
// return paint wasted 
// runtime: O((m+n)logn) 

int main() {
    int n; 
    int m; 

    cin >> n >> m; 

    vector<long> offered_sizes;
    vector<long> desired_sizes;
    long curr; 
    
    // read in paint can sizes offered
    for (int i = 0; i < n; i++) {
        cin >> curr;
        offered_sizes.push_back(curr); 
    }

    for (int i = 0; i < m; i++) {
        cin >> curr; 
        desired_sizes.push_back(curr); 
    }

    // sort offered sizes array because we will binary search!
    sort(offered_sizes.begin(), offered_sizes.end()); 
    sort(desired_sizes.begin(), desired_sizes.end()); 

    int p2 = 0; 
    long curr_desired; 
    long wasted = 0; 

    for (int i = 0; i < m; i++) {
        curr_desired = desired_sizes[i]; 
        while (offered_sizes[p2] < curr_desired) {
            p2++; 
        }
        wasted += offered_sizes[p2] - curr_desired; 
    }

    cout << wasted << endl; 

    return 0; 

}

