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

    int numSubarraysWithSum(vector<int>& arr, int goal) {
        return atMost(arr, goal) - atMost(arr, goal - 1);
    }
};