//Approach : brute force approach : check for all the subarrays and count the frequency of odd and even numbers and if they are equal then update the answer
//T.C : O(n^2)
//S.C : O(n)
// https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-20
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>freq;
            int odd=0;
            int even=0;
            for(int j=i;j<nums.size();j++){
                if(freq.count(nums[j])==0){
                    if(nums[j]%2==0)even++;
                    else odd++;
                    freq[nums[j]]++;
                }
                if(even==odd)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};