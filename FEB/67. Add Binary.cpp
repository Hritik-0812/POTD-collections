//approach : we will start from the end of the strings and we will add the digits and we will keep track of the carry and we will update the answer string accordingly
//T.C : O(n)
//S.C : O(n)  
//https://leetcode.com/problems/add-binary/?envType=daily-question&envId=2026-02-24





class Solution {
public:
    string addBinary(string a, string b) {
        int c=0;
        int n=max(a.size(),b.size());
        string ans="";
        for(int i=n-1;i>=0;i--){
            int d=a.size()>i?a[i]:0;
            int f=b.size()>i?b[i]:0;
            ans.push_back(c^d^f);
            c=(c&d) |c&f;
        }
        if(c==1)ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;

    }
};