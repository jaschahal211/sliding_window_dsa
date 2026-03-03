#include<iostream>
using namespace std;
class Solution {
public:

    int atMost(vector<int>& arr, int goal) {
        if(goal < 0) return 0;

        int l = 0, sum = 0, count = 0;

        for(int r = 0; r < arr.size(); r++) {

            sum += arr[r];

            while(sum > goal) {
                sum -= arr[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        // Convert to 0 (even) and 1 (odd)
        for(int &d : nums) {
            d = d % 2;
        }

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};