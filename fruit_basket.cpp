#include<iostream>
using namespace std;
#include<map>
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        map<int,int>mpp;
        int l=0,r=0,basket=1,maxlen=0;
        while(r<fruits.size())
        {
          mpp[fruits[r]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                {
                    mpp.erase(fruits[l]);
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