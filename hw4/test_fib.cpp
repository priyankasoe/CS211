#include <iostream>
#include <vector> 

using namespace std; 

vector<long> fib(int n);

int main() {
    int n = 777; 
    vector<long> seq = fib(n);

    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << endl; 
    }

    return 0; 
}


vector<long> fib(int n) {

    vector<long> nums; 
    long n1 = 1; 
    long n2 = 1; 
    long temp; 


    for (int i = 0; i < n; i++) {
        if (n1 < 0) {  // handle overflow
            n1 = pow(10, 18);
            for (int j = i; j < n; j++) {
                nums.push_back(n1); 
            }
            break; 
        }
        nums.push_back(n1); 

        temp = n1; 
        n1 = n2; 
        n2 = temp + n2; 
    }



    return nums ;
}