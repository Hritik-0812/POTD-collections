#include<iostream>
using namespace std;  
//https://leetcode.com/problems/binary-gap/description/
/*  
  approach : brute force : convert the number to binary and then find the maximum distance between two 1 in the binary string
  tc: o(log(n)) for converting the number to binary and then o(log(n)) for finding the maximum distance between two 1 in the binary string
  sc: o(log(n)) for storing the binary string
*/

class Solution {
public:
    int binaryGap(int n) {
        string s="";
        while(n>0){
            s.push_back('0'+n%2);
            n=n/2;
        }
        reverse(s.begin(),s.end());
        int ans=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ans=max(count,ans);
                count=0;
            }
            count++;
        }
        return ans;
    }
};



class Solution {
public:
    /*
        approach: constraint 10^9  2^10 ~~1024  2^30 ~~10^9. so we only need to check for the 30 bit 
        of the number by using two pointer curr and prev and use left sift and check for the 
        the current bit is et or not and is there any previous one if yes then update the answer
        by differnce 

        tc:o(32)~o(1)
        sc:o(1)
    */
    int binaryGap(int n) {
        int prev=-1;
        int res=0;
        for(int curr=0;curr<30;curr++){
            if((n>>curr)&1){
                res=prev!=-1?max(res,curr-prev):res;
                prev=curr;
            }
        }
        return res;
    }
};