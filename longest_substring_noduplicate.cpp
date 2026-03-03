#include<iostream>
using namespace std;
#include<map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>mpp;
        int l=0,r=0,maxlen=0;
        if(s.size()==0)
        {
            return 0;
        }
        while(r<s.size())
        {
            while(mpp[s[r]]==1)
            {
                mpp[s[l]] = 0;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            mpp[s[r]]=1;
            r++;
            }
        return maxlen ;
        
    }
};