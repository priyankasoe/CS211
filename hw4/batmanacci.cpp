#include <iostream> 
#include <vector>
#include <cmath> 

using namespace std; 

// logic: 
// get fibonacci numbers of n-1 and n-2 sides of the nth string
// if k is between 0 to n-1th index, recurse through the left half
// if k is between n - (fib(n-2)) - n index, then recurse through 
// right half 
// keep doing this until left and right half are 1 
// and update k pointer to be in respect to the current half it is in 
// ex. if k is letter 5 and it is the right subhalf of an n of length 
// 8, then you have to recurse through the right subhalf which starts
// at index / letter 4, so update k to 2 

char bat(int n, long curr_idx, vector<long> * seq);
vector<long> fib(int n); 


int main() {
    int n;
    long k; 

    cin >> n >> k; 

    // n - nth string in batmanacci 
    // k - kth letter 

    vector<long> fib_nums = fib(n);
    char res = bat(n, k-1, &fib_nums);


    cout << res << endl; 
}

vector<long> fib(int n) {

    vector<long> nums; 
    long n1 = 1; 
    long n2 = 1; 

    nums.push_back(n1); 
    nums.push_back(n2); 
    long temp; 


    for (int i = 2; i < n; i++) {
        temp = nums[i-1]+nums[i-2]; 
        if (temp < 0) {  // handle overflow
            nums.push_back(pow(10, 18));

        } else {
            nums.push_back(temp); 
        }
    }



    return nums ;
}


// recursive helper function 
// n - nth batmanacci element 
// curr_idx is the current desired idx in respect to the nth batmanacci element
// seq is a list of the fibonacci numbers up until + including n  
char bat(int n, long curr_idx, vector<long> * seq) {

    // base case 
    if (n == 1) {
        return 'N';
    }

    if (n == 2) {
        return 'A';
    }


    // get the lengths of the n-1 fib and n-2 fib 
    // -1 bc idx
    long fib_len_n2 = (*seq)[n-2 - 1];  
    long fib_len_n1 = (*seq)[n-1 - 1];

    // if wanted idx is less than number of characters in (n-2)th string
    // --> go through the (n-2)th string 
    if (curr_idx < fib_len_n2) {

        return bat((n-2), curr_idx, seq);  // curr_idx does not need to change cause recursing through first substring 
    }
    // go through the (n-1)th string 
    else {
        // cur_idx has to be updated because now in respect to second substring 
        return bat((n-1), curr_idx - fib_len_n2, seq); 
    }
}