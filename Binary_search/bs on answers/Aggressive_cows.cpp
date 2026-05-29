/*
Question Aggressive cows
IT IS ONE OF THE PATTERN IN BS ON ANSWERS AS IT ASKS TO FIND MIN OF MAX
OR MAX OF MIN

You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an 
integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two
 of them is the maximum possible. Find the maximum possible minimum distance.

Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}.
 Here the distances between cows are 3, 4, and 3 respectively.
We cannot make the minimum distance greater than 3 in any ways.

intuition

first what I did is I tried to fit different combinations of cows position and calculate distances
I got minimum distance from 1 to 3 in above example

i.e. i got range of answers
to exactly identify the minimum value can 1 as there will be atleast two cows
and at max it could be arr[n-1] - arr[i]
i.e. max el in arr - min el in array

so now we have the range of answer we can perform either linear search or binary search to try out the values
and to get good tc we use binary search

now we have to make a function to check whether the cows can be placed or not

we calculate the distacne between the current cow and previous cow and if it is  >= our selected distance 
move to the next cow and update the position of the last cow 

and if  the cows placed are >= given cows return true 
else false

TC :  1. sorting O(nlogn)
2. bs on range O (log (max - min))
3. checking can be placed  O(n)

TC : O(nlogn + n * log (max - min)) 
SC : O(1)
*/ 

#include <bits/stdc++.h>
using namespace std;

bool canBePlaced(vector<int>& arr, int dist, int cows) {

    int n = arr.size();

    int cntCows = 1;
    int last = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] - last >= dist) {
            cntCows++;
            last = arr[i];
        }

        if (cntCows >= cows) return true;
    }

    return false;
}

int max_poss_min_val(vector<int>& arr, int cows) {

    int n = arr.size();

    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr[n - 1] - arr[0];

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canBePlaced(arr, mid, cows) == true) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return high;
}

int main() {

    int n;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cows;
    cout << "Enter number of cows: ";
    cin >> cows;

    cout << "Maximum possible minimum distance is: ";
    cout << max_poss_min_val(arr, cows);

    return 0;
}