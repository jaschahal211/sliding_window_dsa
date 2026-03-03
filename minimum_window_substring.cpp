#include<iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() < t.size()) return "";
        
        vector<int> freq(128, 0);
        
        // Count characters of t
        for(char c : t)
            freq[c]++;
        
        int l = 0, r = 0;
        int count = t.size();   // number of chars still needed
        int minLen = INT_MAX;
        int start = 0;
        
        while(r < s.size()) {
            
            // Include current character
            if(freq[s[r]] > 0)
                count--;
            
            freq[s[r]]--;
            
            r++;
            
            // When window is valid
            while(count == 0) {
                
                if(r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                
                // Remove left character
                freq[s[l]]++;
                
                if(freq[s[l]] > 0)
                    count++;
                
                l++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};