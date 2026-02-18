// approach: brute force approach : check for all the substrings and count the frequency of characters and if they are equal then update the answer
// T.C : O(n^2)
// S.C : O(n) 

//https://leetcode.com/problems/longest-balanced-substring-i/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        if(s.size()==1)return 1;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>freq;
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;
                int fr=0;
                bool flag=false;
                for(auto it:freq){
                    if(fr==0)fr=it.second;
                    if(fr!=it.second){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};