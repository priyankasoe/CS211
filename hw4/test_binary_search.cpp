#include <iostream> 
#include <vector>

using namespace std; 

int binary_search(vector<long> sequence, long element, int n);

int main() {

    int n; 
    cin >> n; 

    int curr; 
    vector<long> sequence;

    for (int i = 0; i < n; i++) {
        cin >> curr;
        sequence.push_back(curr); 
    }

    for (int i = 0; i < n; i++) {
        binary_search(sequence, sequence[i], n);
    }
    cout << "done" << endl;
    return 0; 
}

// Helper function to binary search array
// sequence - array to search, element - item to search for, n - length of array 
// returns index of element 
int binary_search(vector<long> sequence, long element, int n) {
    int l = 0;
    int r = n-1;
 
    int mid;  

    while (l < r) {
        mid = ((l + r)/ 2); 
        if (element == sequence[mid]) {
            return mid; 
        }
        else if (element < sequence[mid]) {
            r = mid-1;   // search in lower half of array
        }
        else {
            l = mid+1;    // search in upper half of array
        }
    }

    if (l == r && l >= 0 && l < n) {
        if (element == sequence[l]) {
            return l;
        }
    }

    return -1; 
}