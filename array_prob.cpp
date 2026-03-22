#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int freq[1000] = {0}; // assuming values < 1000

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "Duplicate elements: ";
    for (int i = 0; i < 1000; i++) {
        if (freq[i] > 1) {
            cout << i << " ";
        }
    }

    return 0;
}
