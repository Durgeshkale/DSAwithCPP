/* Leetcode 31 next permutation
in this problem we have to give the next permutation of the given array as output

so brute appraoc would be generating all the  possible permutations and in sorted order and then we
can find by linear search next permutation but it havs time complexity of n!

so the better solution in cpp would be using stl next_permutation(a.begin(),a.end())

the optimal solution is the implementation of the above

in this appraoch we iterate array from the back side and check where the a[i]<a[i+1] which we call as break point 
were the increasing graphs goes down we call that i as index
and then we iterate over the array from back side again till the index to find the greater value than a[i]
but it must be small than any other so for that we itreate from back and pick the first value which is  greater than a[i]
since teh graph is in increasing order
andn the final step is we reverse the remaining array after the index to ge the smallest array
and this is how we get next permutation 
but if the index remains as -1
that mean it's already  on the highest and last permutation so we reverse the complete array and we get the first permutation which is basically the next to the
last permutation 
*/


#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int index = -1;

    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i = n - 1; i > index; i--) {
        if(nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin() + index + 1, nums.end());
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    nextPermutation(nums);

    cout << "Next permutation is: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}