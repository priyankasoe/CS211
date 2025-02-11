#include <iostream>
#include <vector>

using namespace std; 

int binary_search(vector<long> * sequence, long element, int n);

// SOLUTION: 
// create the finite sequence and store in array 
// loop through array 
// for each element in array, perform a binary search
// on the array for the element 
// if the binary search does not return -1, add to count
// return final count 

// runtime: O(nlogn) 
// n <= 10^6 

int main() {

    // equation: xi = (a*x_i-1 + c) mod m 
    int n;     // length of sequence 
    long m;    // divisor
    long a;    // factor 
    long c;    // additive 

    long x0;   // initial value 

    cin >> n >> m >> a >> c >> x0; 

    vector<long> sequence;

    long curr_term; 
    long prev_term = x0; 

    // fill array with terms 
    for (int i = 0; i < n; i++) {
        curr_term = ((a % m) * (prev_term % m) + (c % m)) % m; 
        sequence.push_back(curr_term); 
        prev_term = curr_term; 
    }

    int count = 0; 

    // do binary search on elements of sequence
    for (int i = 0; i < n; i++) {

        // if returns a valid idx = found 
        if (binary_search(&sequence, sequence[i], n) != -1) {
            count++; 
        }
    }

    cout << count << endl; 
    return 0; 
}

// Helper function to binary search array
// sequence - array to search, element - item to search for, n - length of array 
// returns index of element 
int binary_search(vector<long> * sequence, long element, int n) {
    int l = 0;
    int r = n-1;
 
    int mid;  

    while (l <= r) {
        mid = ((l + r)/ 2); 
        if (element == (*sequence)[mid]) {
            return mid; 
        }
        else if (element < (*sequence)[mid]) {
            r = mid-1;   // search in lower half of array
        }
        else {
            l = mid+1;    // search in upper half of arraya
        }
    }

    return -1; 
}
