/* In the given array we have to find out the missing number and the repeating number
to solve this first we xor the array elements with 1-N
and we get a no. 
then we check for the set bit at what bit no . the set index is 
as soon as we get the bit no. we divide all of our no.s in two side 
one side having bit 1 at bit no. and other is have 0 at bitno
then we xor all the elements on both side and we are left with 
one element on both side( since we have all the elements even times
except for teh repeating and missing they are odd times )

then we iterate over the array and count which nums have count 2
the no. with count 2 is set a repeating and the other no. is set as missing */

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();

    int xr = 0;

    for(int i = 0; i < n; i++) {
        xr = xr ^ nums[i];
        xr = xr ^ (i + 1);
    }

    int bitNo = 0;
    while(true) {
        if((xr & (1 << bitNo)) != 0) {
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;

    for(int i = 0; i < n; i++) {
        if((nums[i] & (1 << bitNo)) != 0) {
            one = one ^ nums[i];
        }
        else {
            zero = zero ^ nums[i];
        }
    }

    for(int i = 1; i <= n; i++) {
        if((i & (1 << bitNo)) != 0) {
            one = one ^ i;
        }
        else {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == zero) {
            cnt++;
        }
    }

    if(cnt == 2) {
        return {zero, one};   // zero = repeating, one = missing
    }

    return {one, zero};       // one = repeating, zero = missing
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 3};

    vector<int> ans = findMissingRepeatingNumbers(nums);

    cout << "Repeating Number: " << ans[0] << endl;
    cout << "Missing Number: " << ans[1] << endl;

    return 0;
}