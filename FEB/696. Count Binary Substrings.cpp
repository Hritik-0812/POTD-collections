// my approach is like 2 pointers appraoch where first place the first pointer at the start of the string and the second pointer at the end of the string and then we will check if the characters at both pointers are same or not if they are same then we will move the second pointer towards the left until we find a different character and then we will check if the number of characters between the two pointers are same or not if they are same then we will move the first pointer towards the the strat of the first group then iterate the j for the second group take mininmum and add to the ans and reset the count of the first group and set the first pointer to second pointer and repeat the process until the second pointer reaches the end of the string
//T.C : O(n)
//S.C : O(1)

//https://leetcode.com/problems/count-binary-substrings/description/  
#include<iostream>
using namespace std;
int countBinarySubstrings(string s) {
    int zeros=0;
    int ones=0;
    int i=0;
    int n=s.size();
    for(i=0;i<s.size()-1;i++){
        if(s[i]=='1')ones++;
        else zeros++;
        if(s[i]!=s[i+1])break;
    }

    int ans=0;
    int j=i+1;
    while(j<n){
        int prev=s[j];
        while(s[j]==prev){
            if(s[j]=='1')ones++;
            else zeros++;
            j++;
        }
        ans+=min(zeros,ones);
        if(s[i]=='1')ones=0;
        else zeros=0;
        i=j-1;
    }
    return ans;
  }   
  
  int main() {
    string s = "0011";
    int result = countBinarySubstrings(s);
    cout << "Number of binary substrings: " << result << endl;
    return 0;
  }




// optimization : instead of the fixing first pointer to the first group we can do that it in second  loop and instead of reseting we overide the count of the group thus onlu need one pointer instead of two
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeros=0;
        int ones=0;
        int i=0;
        int n=s.size();
        int ans=0;
        while(i<n){
            int curr=s[i];
            int count=0;
            while(i<n && s[i]==curr){
                count++;
                i++;
            }
            if(curr=='1')ones=count;
            else zeros=count;
            ans+=min(zeros,ones);
        }
        return ans;
    }             
};