#include <iostream> 
#include <vector>
using namespace std;

// merge sort algorithm from geeks4geeks, link: https://www.geeksforgeeks.org/cpp-program-for-merge-sort/

void merge(vector<long> * vec, int left, int mid, int right, long * swaps);
void mergeSort(vector<long> * vec, int left, int right, long * swaps);

// Merges two subarrays of vec.
// First subarray is vec[left..mid]
// Second subarray is vec[mid+1..right]
void merge(vector<long> * vec, int left, int mid, int right, long * swaps) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<int> leftVec(n1), rightVec(n2);

    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftVec[i] = (*vec)[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = (*vec)[mid + 1 + j];

    // Merge the temporary vectors back into vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            (*vec)[k] = leftVec[i];
            i++;
            // if (i < j) {
            //     (*swaps)++; 
            // }
        } else {
            (*vec)[k] = rightVec[j];
            j++;
            (*swaps) += n1 - i; 
        }
        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        // if (i <= j) {
        //     (*swaps)++; 
        // }
        (*vec)[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        (*vec)[k] = rightVec[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(vector<long> * vec, int left, int right, long * swaps) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(vec, left, mid, swaps);
        mergeSort(vec, mid + 1, right, swaps);

        // Merge the sorted halves
        merge(vec, left, mid, right, swaps);
    }
}

int main() {

    int n; 
    cin >> n; 

    vector<long> vec;
    long curr; 

    for (int i = 0; i < n; i++) {
        cin >> curr; 
        vec.push_back(curr); 
    }

    long n_swaps = 0; 

    // Sorting vec using mergesort
    mergeSort(&vec, 0, n - 1, &n_swaps);

    cout << n_swaps << endl;
    return 0;
}