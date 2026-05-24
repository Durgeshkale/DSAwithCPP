/*
Leetcode 875 Koko Eating Bananas
Koko loves to eat bananas.
There are n piles of bananas, where piles[i] represents the number of bananas
in the ith pile.
Koko can choose an eating speed k, where k means she eats k bananas per hour.
Return the minimum integer k such that Koko can eat all bananas within h hours.

Example:
Input:
piles = [3,6,7,11], h = 8
Output:
4

Intuition:
We could solve this using linear search from 1 to max pile size.
For every speed, we calculate total hours required.
But this can be slow.
TC = O(max(piles) * n)

The possible answer range is clearly from:
1 to max(piles)

So we can apply Binary Search on Answer.

If Koko can finish bananas in less than or equal to h hours,
then this speed works, so we try to minimize the speed.

If Koko takes more than h hours,
then speed is too small, so we increase the speed.
TC = O(n * log(max(piles)))
*/

#include <bits/stdc++.h>
using namespace std;

long long total_Hours(vector<int>& arr, int k) {

    long long total_hrs = 0;

    for (int i = 0; i < arr.size(); i++) {
        total_hrs += ceil((double)arr[i] / k);
    }

    return total_hrs;
}

int minEatingSpeed(vector<int>& piles, int h) {

    int maxNana = *max_element(piles.begin(), piles.end());

    int low = 1;
    int high = maxNana;

    int ans = maxNana;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        long long req_time = total_Hours(piles, mid);

        //when koko finishes banana in h hrs we try to minimize eating speed
        if (req_time <= h) {

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
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;
    cout << "Enter total hours: ";
    cin >> h;

    cout << "Minimum eating speed is: " << minEatingSpeed(piles, h);

    return 0;
}