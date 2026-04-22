/*Leetcode 56 Merge Intervals
what we  had to do is check if there exist intervals which overlaps and had to merge them */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solveMergeIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

void printIntervals(const vector<vector<int>>& ans) {
    cout << "Merged intervals are:" << endl;
    for (auto interval : ans) {
        cout << "[ " << interval[0] << " " << interval[1] << " ]" << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> ans = solveMergeIntervals(intervals);

    printIntervals(ans);

    return 0;
}