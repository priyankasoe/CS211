#include <iostream>
#include <sstream> 
#include <string> 
#include <tuple> 
#include <queue> 
#include <cmath> 

using namespace std; 

struct city_obj_t {
    float votes_per_box;
    int boxes; 

    bool operator<(const city_obj_t& other) const {
        return votes_per_box < other.votes_per_box; // Prioritize based on votes per box 
    }
}; 


int main() {

    vector<int> max_ballots; 

    while (true) {
        int cities; 
        int boxes; 
        cin >> cities >> boxes; 

        // check if end of input 
        if (cities == -1 && boxes == -1) {
            break; 
        }

        priority_queue<city_obj_t> pop_arr; 
        city_obj_t curr_obj; 
        int curr_pop; 

        for (int i = 0; i < cities; i++) {
            cin >> curr_pop;
            curr_obj.votes_per_box = curr_pop;
            curr_obj.boxes = 1;
            pop_arr.push(curr_obj);
        }

        boxes -= cities; 
        city_obj_t updated;

        while (boxes > 0) {
            city_obj_t largest = pop_arr.top(); 
            pop_arr.pop(); 

            updated.votes_per_box = (largest.votes_per_box * largest.boxes) / (largest.boxes + 1);
            updated.boxes = largest.boxes + 1;

            pop_arr.push(updated); 
            boxes -= 1; 
        }

        max_ballots.push_back(ceil(pop_arr.top().votes_per_box)); 

        cin.ignore(); 
    }

    for (int i = 0; i < max_ballots.size(); i++) {
        cout << max_ballots[i] << "\n";
    }
   

}
