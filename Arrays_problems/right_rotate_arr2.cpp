#include <bits/stdc++.h>
using namespace std;

void rotateRight(vector<int>& arr, int d) {
    int n = arr.size();

    d = d % n;   

    reverse(arr.begin(), arr.end());           
    reverse(arr.begin(), arr.begin() + d);     
    reverse(arr.begin() + d, arr.end());       
}

int main() {
    int n, d;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of places to rotate right: ";
    cin >> d;

    rotateRight(arr, d);

    cout << "Array after right rotation: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}