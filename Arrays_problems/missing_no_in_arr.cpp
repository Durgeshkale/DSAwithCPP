#include <iostream>
#include <vector>
using namespace std;

/*optimal approach it is we calculate the sum of array and 
sum of n natural numbers and then substracted the sum of array 
from the expected sum which is sum of n natural no. the result is our missing number. */

int missingNum(vector<int> &arr) {
    int n = arr.size() + 1;
  
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    long long expSum = (n *1LL* (n + 1)) / 2;  

    return expSum - sum;
}

int main() {
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};  
    cout << missingNum(arr);  
    return 0;
}