/* leetcode 560 Subarray array sum equals k
in this array we have to give output the total no. of sub array who's sum is equal to k
to solve this problem we used hashmap were we stored the prefix sum and check if there  exist any s-k in pervious part of subarray 
if yes then we increase the cntsr(counter of sub array with sum equals k) and 
in hash map we store prefix sum and cnt as key this cnt counts the no. of occcurance of prefix sum 
what exactly we do is we calculate s-k and then we check in hash map if there exist any stored prefix sum = k if not then we store current prefix sum and 
move forward if yes then we increase the cntsr*/


#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int,int> mp;
    mp[0] = 1;
    int presum = 0, cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        presum += nums[i];
        int remove = presum - k;
        cnt += mp[remove];
        mp[presum] += 1;
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> k;

    cout << subarraySum(nums, k);

    return 0;
}