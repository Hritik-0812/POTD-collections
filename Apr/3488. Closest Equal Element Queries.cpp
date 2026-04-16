
//Problem Link - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/

//Approach - Store in map and use binary search to find indices
//T.C : O(Q * log(n))
//S.C : O(n)

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector < int > res ;
        unordered_map < int, vector< int > > mpp ;
        int n = nums.size() ;

        // storing position of same element in map
        for ( int i = 0 ; i < n ; i++ ) {
            mpp[ nums[ i ] ].push_back( i ) ;
        }

        for ( auto qi : queries ) {

            int ele = nums[ qi ] ;

            // refernce to the map vector not creating a another vector
            auto &it = mpp [ ele ] ;
            int s = it.size() ;
            
            //edge case no other index is present
            if( s == 1 ){
                res.push_back( -1 ) ;
                continue ;                
            }

            int ans = INT_MAX ;

            // finding the index of the ele in it vector
            int pos = lower_bound ( it.begin(), it.end(), qi ) - begin( it ) ;

            // real ind
            int ind = it[ pos ] ;

            // right neighbour pos+1
            int right = it[ ( pos + 1 ) % s ] ;
            int d = abs( right - ind ) ; // straight distance
            int circular_dis = n - d  ;
            ans= min( ans , min( d , circular_dis ) ) ;


            // left neighbour pos-1
            int left = it[(pos - 1 + s) % s] ;
            d = abs( left - ind ) ; // straight distance
            circular_dis = n - d ;
            ans= min( ans , min( d , circular_dis ) ) ;

            res.push_back( ans ) ;

        }
        return res;
    }
};