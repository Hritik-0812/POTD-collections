class Solution {
public:
    /*
    aproach : store the number of set bit and there number in hashmap in the format of int,
    vector and sort thr vector befor including in answer

    tc : o(nlogn)
    sc : o(n)
    */
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mpp;
        for(auto it:arr){
            mpp[__builtin_popcount(it)].push_back(it);
        }
        vector<int>ans;
        for(auto [e,it]:mpp){
            vector<int> v=it;
            sort(v.begin(),v.end());
            for(auto e:v){
                ans.push_back(e);
            }
        }
        return ans;
    }
};