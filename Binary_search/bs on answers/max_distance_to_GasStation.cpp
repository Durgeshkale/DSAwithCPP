/*
Leetcode premium problem
Question: Minimize Max Distance to Gas Station

We are given positions of existing gas stations in sorted order.
We have to add K new gas stations anywhere between existing stations.

Return the minimum possible value of the maximum distance between
two adjacent gas stations after adding all K stations.

Example:
Input:
stations = [1, 2, 3, 4, 5]
K = 4

Output:
0.5

Explanation:
We can place one gas station between every adjacent pair.
So the maximum distance becomes 0.5.

Intuition:
We need to minimize the maximum distance between two adjacent stations.

The best idea is:
Whenever we add a new gas station, we should add it in the section
which currently has the maximum distance.

If a section has length diff and we add x gas stations inside it,
then it gets divided into x + 1 parts.

So new section length becomes:
diff / (x + 1)

Brute force:
For every gas station from 1 to K,
we can find the current maximum section by checking all sections.

TC = O(K * N)

This can give TLE.

Optimization:
Instead of searching maximum section manually every time,
we use a priority queue.

Priority queue always keeps the current largest section on top.

So:
- push all initial section lengths into priority queue
- each time pick the largest section
- add one station in that section
- update its new section length
- push it back into priority queue

After placing all K stations,
pq.top().first gives the minimized maximum distance.

Time Complexity: O(N log N + K log N)

N log N -> pushing initial sections into priority queue
K log N -> for every new gas station, pop and push operation

Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

long double minMaxDist(vector<int> &stations, int K) {

    int n = stations.size();

    if (n <= 1) return 0.0;

    vector<int> howMany(n - 1, 0);

    //pushing all the difference(distance) in the priority queue
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++) {
        pq.push({stations[i + 1] - stations[i], i});
    }

    for (int gasStation = 1; gasStation <= K; gasStation++) {

        auto tp = pq.top();
        pq.pop();

        int secInd = tp.second; // assigning index value to secInd

        howMany[secInd]++;

        long double iniDiff = stations[secInd + 1] - stations[secInd]; // initial max diff

        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);

        pq.push({newSecLen, secInd});
    }

    return pq.top().first; //returns minimized max distance
}

int main() {

    int n;
    cout << "Enter number of gas stations: ";
    cin >> n;

    vector<int> stations(n);

    cout << "Enter gas station positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    int K;
    cout << "Enter number of new gas stations: ";
    cin >> K;

    cout << fixed << setprecision(6);
    cout << "Minimum possible maximum distance is: ";
    cout << minMaxDist(stations, K);

    return 0;
}
