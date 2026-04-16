class Solution {
public:
    /* 
    approach : generate all substring of size k using sliding window and insert in set if the 
    combination in equal to the 2^k then true else false

    tc: o(n)
    sc:o(2^k)
    
    /https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/   
    */
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        unordered_set<int>st;
        int res=0;
        int mask =(1<<k)-1;
        for(int i=0;i<k;i++){
            res = (res<<1)|(s[i]-'0');
        }
        st.insert(res);
        for(int i=k;i<s.size();i++){
            res = ((res<<1 )& mask)|(s[i]-'0');
            st.insert(res);
        }
        return st.size()==(1 << k);
    }
};