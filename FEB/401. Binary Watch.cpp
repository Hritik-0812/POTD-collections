//approach : we will iterate through all the possible hours and minutes and we will count the number of bits that are set in the hours and minutes and if the count is equal to turnedOn then we will add the time to the answer vector
//T.C : O(12*60) => O(1)
//S.C : O(1) (not considering the answer vector)
//https://leetcode.com/problems/binary-watch/?envType=daily-question&envId=2026-02-21



class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
                    string h=to_string(i);
                    string m=(j<10?"0":"")+ to_string(j);
                    ans.push_back(h+":"+m);
                }
            }
        }
        return ans;
    }
};