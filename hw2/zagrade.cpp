#include <iostream>
#include <tuple> 
#include <vector>
#include <stack> 
#include <string>

// no more than 10 pairs of brackets 

// data structure to hold pairs of brackets (array of tuples)
// tuple: (starting index, ending index) 

// read through characters into a stack 
// keep adding to stack until reach a opening/closing => then pop off top 
// do this until stack is empty 

// visited 

using namespace std;

vector<vector<tuple<int, int> > > find_subsets(vector <tuple<int, int> > set, vector <vector <tuple<int, int> > > subsets, int set_size,  int curr_idx);

int main() {
    // to store strression 
    string str; 
    // str.reserve(200);   // strression is at most 200 characters 

    // read in input 
    cin >> str;
    int len = str.size();

    // array of tuples to store pairs of brackets
    // vector stores starting index of each pair of brackets 
    vector< tuple<int, int> > brackets; 

    // stack of tuples in form (idx, char at idx) 
    stack< tuple<int, char> > charStack; 

    charStack.push({0, str[0]});
    int i = 1; 
    int prev_j = 0; 


    while (i < len) {
        
        // pop from stack until reaching starting bracket
        // record index of starting bracket
        if (str[i] == ')') {

            while (get<1>(charStack.top()) != '(') {
                charStack.pop(); 
            }

            // j will now be starting index of opening bracket
            brackets.push_back({get<0>(charStack.top()), i});
            charStack.pop();   // pop the opening bracket 
            i++;
            continue; 
        }

        charStack.push({i, str[i]});

        // if (i < len) {
        //     charStack.push({i, str[i]});
        // } else if (charStack.empty()) {
        //     break; 
        // } else {   // if reaches end, pop from stack 
        //     charStack.pop(); 
        // }

        i++;
    }

   // cout << "found all pairs of brackets\n";
    // for (int i = 0; i < brackets.size(); i++) {
    //     cout << get<1>(brackets[i]) << endl; 
    // }

    vector< vector<tuple<int, int> > > all_subsets; 
    all_subsets = find_subsets(brackets, all_subsets, brackets.size(), 0);
    vector<string> possible_strings; 

    // runs at most 2^10 times = 1024 
    // inner for loop will run at most 10 times (at most 10 pairs of brackets)

    // so total 1024 * 10 = 10,240
     // the first subset will always be the empty set ==> ignore because that is same as initial expression
    for (int i = 1; i < all_subsets.size(); i++) {
        vector<tuple<int, int> > curr_subset = all_subsets[i];
        vector<int> idx_to_remove; 
        string curr_str = ""; 
        curr_str.reserve(len);

        for (int j = 0; j < curr_subset.size(); j++) {

            idx_to_remove.push_back(get<0>(curr_subset[j])); 
            idx_to_remove.push_back(get<1>(curr_subset[j])); 
           
        }

        sort(idx_to_remove.begin(), idx_to_remove.end()); 
        int remove_ptr = 0; 
        for (int i = 0; i < len; i++) {
            if (remove_ptr < idx_to_remove.size()) {
                if (idx_to_remove[remove_ptr] != i) {
                    // don't add 
                    curr_str += str[i]; 
                } else {    // not adding, move onto next bracket to not add
                    remove_ptr++; 
                }
            } else {
                curr_str += str[i]; 
            }
        }

        bool flag = false; 

        if (possible_strings.size() != 0) {
            for (int p = 0; p < possible_strings.size(); p++) {
                if (possible_strings[p] == curr_str) {
                    flag = true;
                }
            }
            if (!flag) {
                possible_strings.push_back(curr_str); 
            }
        } else {
            possible_strings.push_back(curr_str);  
        }
    }

    sort(possible_strings.begin(), possible_strings.end()); 
    for (int i = 0; i < possible_strings.size(); i++) {
        cout << possible_strings[i] << endl; 
    }


}

vector<vector<tuple<int, int> > > find_subsets(vector <tuple<int, int> > set, vector <vector <tuple<int, int> > > subsets, int set_size, int curr_idx) {

    if (curr_idx == set_size) { 
        return subsets;
    }

    if (curr_idx == 0) {
        // empty set 
        subsets.push_back({});
        vector<tuple<int, int> > new_subset = {set[0]};
        subsets.push_back(new_subset);
        return find_subsets(set, subsets, set_size, curr_idx+1); 
    }

    // make two copies of current subsets and add n to each 

    // i iterates through previous subsets
    int curr_subsets = subsets.size(); 
    for (int i = 0; i < curr_subsets; i++) {
        vector<tuple<int, int> > new_subset = subsets[i];
        new_subset.push_back(set[curr_idx]); 
        subsets.push_back(new_subset);
    }

    return find_subsets(set, subsets, set_size, curr_idx+1); 
}
