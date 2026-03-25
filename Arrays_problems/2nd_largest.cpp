#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// This program finds the secondlargest  and second smallest element in an array of integers.

int secondLargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    int second_largest = -1; // in case of array with negative numbers use int max
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int secondSmallest(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int second_smallest = INT_MAX; // in case of array with positive numbers use int max

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }
    }
    return second_smallest;
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    vector<int> arr;

    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        arr.push_back(value);
    }

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The second largest element in the array is: " << secondLargest(arr, n)<<endl;
    cout << "The second smallest element in the array is:" << secondSmallest(arr, n);
    return 0;
}
