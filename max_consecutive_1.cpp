#include<iostream>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,count=0,maxlen=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                count++;
            }
            while(count>k)
            {
                if(nums[l]==0){
                count--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};