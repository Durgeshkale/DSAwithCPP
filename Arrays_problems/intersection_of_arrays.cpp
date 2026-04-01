//intersection of two sorted arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> InsArr;

    while(i< n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<a[i]){
            j++;
        }
        else{
            InsArr.push_back(a[i]);
            i++;
            j++;
        }

    }

    return InsArr;
}

int main() {
    int n1, n2;

    cout << "Enter size of first sorted array: ";
    cin >> n1;

    vector<int> a(n1);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> n2;

    vector<int> b(n2);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    vector<int> result = sortedArray(a, b);

    cout << "Intersection of both sorted arrays: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}