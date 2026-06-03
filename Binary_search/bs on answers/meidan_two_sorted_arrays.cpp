/*
Question:
Leetcode 4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

Example 1:
Input:
nums1 = [1,3]
nums2 = [2]

Output:
2.0

Explanation:
Merged array = [1,2,3]
Middle element = 2

Example 2:
Input:
nums1 = [1,2]
nums2 = [3,4]

Output:
2.5

Explanation:
Merged array = [1,2,3,4]
Median = (2 + 3) / 2 = 2.5


Brute Force Approach

Intuition:
Since both arrays are already sorted,
we can merge them into a single sorted array.

Once we get the final sorted array:

If total number of elements is odd:
Median = middle element

If total number of elements is even:
Median = (n/2 th element + (n/2 - 1) th element) / 2

Approach:
1. Merge the two sorted arrays.
2. Find total size = n1 + n2.
3. Check whether size is odd or even.
4. If odd, return middle element.
5. If even, return average of middle two elements.

This is a brute force approach because:
- We traverse both arrays completely.
- We create an extra merged array.


Time Complexity: O(n1 + n2)

Space Complexity: O(n1 + n2)


//brute approach
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> nums3;

    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0;
    int j = 0;

    // merge both sorted arrays
    while(i < n1 && j < n2) {

        if(nums1[i] < nums2[j]) {
            nums3.push_back(nums1[i++]);
        }

        else {
            nums3.push_back(nums2[j++]);
        }
    }

    // copy remaining elements of first array
    while(i < n1) {
        nums3.push_back(nums1[i++]);
    }

    // copy remaining elements of second array
    while(j < n2) {
        nums3.push_back(nums2[j++]);
    }

    int n = n1 + n2;

    // odd number of elements
    if(n % 2 == 1) {
        return nums3[n / 2];
    }

    // even number of elements
    return ((double)nums3[n / 2] + (double)nums3[n / 2 - 1]) / 2.0;
}

*/

/*better approach reducing extra space

Here we don't create the merged array.

We only need two middle elements:
ind1 = n/2 - 1
ind2 = n/2

So while merging, we just count the current index
and store only those two required elements.

This reduces space from O(n1 + n2) to O(1).
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
Better Approach:
Here we don't create the merged array.

We only need two middle elements:
ind1 = n/2 - 1
ind2 = n/2

So while merging, we just count the current index
and store only those two required elements.

This reduces space from O(n1 + n2) to O(1).
*/
//better approach
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0;
    int j = 0;

    int n = n1 + n2;

    int ind2 = n / 2;
    int ind1 = ind2 - 1;

    int cnt = 0;

    int ind1el = -1;
    int ind2el = -1;

    while(i < n1 && j < n2) {

        if(nums1[i] < nums2[j]) {

            if(cnt == ind1) ind1el = nums1[i];
            if(cnt == ind2) ind2el = nums1[i];

            cnt++;
            i++;
        }

        else {

            if(cnt == ind1) ind1el = nums2[j];
            if(cnt == ind2) ind2el = nums2[j];

            cnt++;
            j++;
        }
    }

    while(i < n1) {

        if(cnt == ind1) ind1el = nums1[i];
        if(cnt == ind2) ind2el = nums1[i];

        cnt++;
        i++;
    }

    while(j < n2) {

        if(cnt == ind1) ind1el = nums2[j];
        if(cnt == ind2) ind2el = nums2[j];

        cnt++;
        j++;
    }

    if(n % 2 == 1) {
        return ind2el;
    }

    return ((double)ind1el + (double)ind2el) / 2.0;
}

int main() {

    int n1;
    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> nums1(n1);

    cout << "Enter elements of first sorted array: ";
    for(int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    int n2;
    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> nums2(n2);

    cout << "Enter elements of second sorted array: ";
    for(int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    cout << "Median is: ";
    cout << findMedianSortedArrays(nums1, nums2);

    return 0;
}