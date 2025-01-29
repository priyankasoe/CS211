#include <iostream>

using namespace std;

int main() {
    while (true) {
        int arr[500][500] = {0};
        int num_squares = 0;
        int num_rect;
        cin >> num_rect; 
        if (num_rect == 0) {
            break;
        }
        for (int i = 0; i < num_rect; i++) {
            int a; 
            int b;
            int c; 
            int d; 
            cin >> a >> b >> c >> d;
            for (int x = a; x < c; x++) {
                for (int y = b; y < d; y++) {
                    if (arr[x][y] == 0) {
                        num_squares++;
                        arr[x][y] = 1; 
                    }
                }
            }
        }
        cout << num_squares << endl;
    }
}