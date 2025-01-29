#include <iostream>
#include <vector>
#include <sstream> 

using namespace std;

int main() {

    vector< vector<string> > output; 

    int img_num = 0; 

    while (true) {  // reading input         
        int n; 
        cin >> n;
        if (n == 0) {
            break; 
        } 
        vector<string> curr_img; 
        curr_img.reserve(n); 
        cin.ignore(); 

        for (int i = 0; i < n; i++) {
            string curr_line;
            string processed; 

            getline(cin, curr_line);
            stringstream ss(curr_line); 
            char curr;
            ss >> curr; 
            int run;

            // turn the string into parsed image 

            while (ss >> run) {

                for (int k = 0; k < run; k++) {
                    processed += curr; 
                }
                curr = (curr == '#') ? '.' : '#';
            }
            curr_img.push_back(processed); 
        }

        // add to output vector 

        output.push_back(curr_img); 
        img_num++; 
    }

    // print output

    for (int p = 0; p < img_num; p++) {
        
        // sums for checking if every line is equal 
        int prev_sum = output[p][0].size(); 
        int curr_sum = 0; 

        // will set if unequal line 
        char wrong_input_flag = '0'; 
        int n = output[p].size(); 

        // iterate through output vector to print 
        for (int m = 0; m < n; m++) {
            curr_sum = output[p][m].size(); 
            if (curr_sum != prev_sum) {
                wrong_input_flag = '1';
            }
            cout << output[p][m];
            cout << endl; 
            prev_sum = curr_sum; 
        }
        if (wrong_input_flag != '0') {
            cout << "Error decoding image";
            if (p != img_num-1) {
                cout << endl;
            }
        }
        cout << endl; 
    }

}