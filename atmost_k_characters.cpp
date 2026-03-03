#include<iostream>
using namespace std;
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int l=0,r=0,maxlen=0;
        map<char,int>mpp;
        while(r<s.size())
        {
            mpp[s[r]]++;
            while(mpp.size()>k)
            {
                mpp[s[l]]--;
                if(mpp[s[l]]==0)
                {
                    mpp.erase(s[l]);
                }
                l++;
            }
                maxlen=max(maxlen,r-l+1);
            r++;

        }
        return maxlen;
        //your code goes here
    }
};