/*
Leetcode 1482 
Minimum Number of Days to Make m Bouquets

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Intution:

if we carefully observe we have to find minimum number of days required
and the bloomday are given 
so the answer will be from minimum day of bloom day to maximum day of bloomday

so here we can perform binary search on answe to find minimum no. of days

Approach:

first we find min and max element in the bloomday and assign low = min and high = max
then we apply while loop
and then we calculate mid 

and check is for that mid i.e. no. of bloom day is it possible to make required bouquets if true
we assign ans = mid 
and check in the left i.e no. high = mid - 1
else
we need higher no. of bloomday to make bouquets 

now to check if the no. of bouquets can be made or not
there are two constraints 
first ith flower will bloom on ith day
and second is bouquets can be made from adjacent flowers only

so
to check if the mid = day is possible or not

we keep cnt = 0 
and then iterate over the array
if the arr[i] day is <= day
then we increase cnt 
else 
we count how many bouquets can be made at that cnt of flowers
and cnt = 0 since it won't be adjacent anymore
and keep checking till the complete array is traversed
and after the loop ends 
we still have new cnt so add if any bouquets can be made from that cnt

if the no. of bouquets are greater than m i.e. required bouquets then return true else false

Time Complexity: O(n * log(maxDay - minDay))
Space Complexity: O(1)
*/ 

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& arr, int day, int m, int k) {

    int n = arr.size();

    int cnt = 0;
    int no_of_bouquet = 0;

    for (int i = 0; i < n; i++) {

        // if flower has bloomed on or before current day
        if (arr[i] <= day) {
            cnt++;
        }

        // if flower has not bloomed, break the adjacent chain
        else {
            no_of_bouquet += cnt / k;
            cnt = 0;
        }
    }

    // count bouquet from remaining adjacent flowers
    no_of_bouquet += cnt / k;

    return no_of_bouquet >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {

    int n = bloomDay.size();

    long long req_flowers = 1LL * m * k;

    // if required flowers are more than available flowers
    if (req_flowers > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // if bouquets can be made on this day, try to minimize days
        if (possible(bloomDay, mid, m, k) == true) {
            ans = mid;
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> bloomDay(n);

    cout << "Enter bloom days: ";
    for (int i = 0; i < n; i++) {
        cin >> bloomDay[i];
    }

    int m, k;

    cout << "Enter number of bouquets: ";
    cin >> m;

    cout << "Enter flowers needed per bouquet: ";
    cin >> k;

    cout << "Minimum number of days: " << minDays(bloomDay, m, k);

    return 0;
}