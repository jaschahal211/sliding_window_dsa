#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int l = 0, count = 0;
        vector<int> hash(3, 0);
        
        for(int r = 0; r < s.size(); r++) {
            
            hash[s[r] - 'a']++;
            
            while(hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
                
                count += s.size() - r;
                
                hash[s[l] - 'a']--;
                l++;
            }
        }
        
        return count;
    }
};