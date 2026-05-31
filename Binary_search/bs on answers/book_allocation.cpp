/*
Question: Allocate Minimum Number of Pages / Book Allocation

Given an array arr[] where arr[i] represents the number of pages in the ith book,
and an integer k representing the number of students.

We have to allocate books to students such that:
1. Each student gets at least one book.
2. Each book should be allocated to exactly one student.
3. Books should be allocated in contiguous order.
4. We need to minimize the maximum number of pages assigned to any student.

If allocation is not possible, return -1.

Example:
Input:
arr = [12, 34, 67, 90]
k = 2

Output:
113

Explanation:
One possible allocation:
Student 1: 12 + 34 + 67 = 113 pages
Student 2: 90 pages

Maximum pages = 113

This is the minimum possible maximum number of pages.

Intuition:
First, we check when to return -1.
If number of students is greater than number of books, then allocation is not possible.

Now we need to find the minimum possible maximum pages.

The minimum possible answer can be:
max element of the array

Because if number of books and students are equal,
each student gets one book, so the answer will be the book with maximum pages.

The maximum possible answer can be:
sum of all pages

Because if there is only one student,
that student has to read all books.

So our answer lies in the range:
max(arr) to sum(arr)

We can do linear search in this range,
but since we have a sorted answer range, we use Binary Search on Answer.

For every mid:
mid represents the maximum pages allowed for one student.

If books can be allocated within k students,
then mid is a possible answer, so we try to minimize it.

If books need more than k students,
then mid is too small, so we increase the pages.

Time Complexity: O(n * log(sum - max))

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int cntStudent(vector<int>& arr, int pages) {

    int student = 1;
    int pages_student = 0;

    for (int i = 0; i < arr.size(); i++) {

        if (pages_student + arr[i] <= pages) {
            pages_student += arr[i];
        }

        else {
            student++;
            pages_student = arr[i];
        }
    }

    return student;
}

int findPages(vector<int>& arr, int k) {

    int n = arr.size();

    if (k > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int student = cntStudent(arr, mid);

        if (student > k) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter pages of books: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter number of students: ";
    cin >> k;

    cout << "Minimum possible maximum pages: ";
    cout << findPages(arr, k);

    return 0;
}
