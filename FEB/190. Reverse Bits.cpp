//approach : left shift the answer and add the last bit of n to the answer and right shift n to get the next bit and repeat this process for 32 bits
//T.C : O(32) => O(1)
//S.C : O(1)
//https://leetcode.com/problems/reverse-bits/?envType=daily-question&envId=2026-02-17


class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            ans=(ans<<1)|(n&1);
            n=n>>1;
        }      
        return ans;
    }
};