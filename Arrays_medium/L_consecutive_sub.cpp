/* leetcode 128 Longest consecutive subsequence 
i.e the array element which are just next to each other and maximum length of the consecutive subsequence they can form 
so until and unless we are not given with the worst case we can use unordered set to solve this question but if 
we're given with wrost case
we will have to use a better solution in which we sort the array first and then iterate over the array and check if there exist 
and element just after the current element and then we store it's result in longest

In the current set solution we add all the array elements into the set 
then we iterate over the set can check if the element previous to the current element exists or
not if it exist we move to the next element cause it can't be the starting element
then as we get the starting element we keeping the elements just after this and continue to increase the 
cnt and longest which is our answer until the sequence ends in best and avg case it gives tc O(1)*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;

    for(int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;

            while(st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt += 1;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
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

    int ans = longestConsecutive(nums);

    cout << "Length of longest consecutive sequence is: " << ans << endl;

    return 0;
}