
// problem link : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/

/* 01 approach : pick element from one and do the binary search on other array to fing the index 
   Tc : o(nlog(m)) 
   Sc : o(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        int ans = 0 ;
        for( int i = 0 ; i < n ; i ++ ) {
            int ele = nums1 [ i ] ; 
            int low = i ;
            int high = m - 1 ;
            while ( low <= high ) {
                int mid = low - ( low - high ) / 2 ;
                if ( nums2 [ mid ] >=  ele ) {
                    ans = max ( ans , mid -i ) ;
                    low = mid + 1 ; 
                }
                else high = mid -1 ;
            }
                    
        }
        return ans;
    }
};


/* 02 approach : Two Pointers 
   Tc : o(n+m) 
   Sc : o(1)
*/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0 , res = 0 , n = nums1.size() , m = nums2.size() ;
        while ( i != n && j != m ) {
            if ( nums1 [ i ] <= nums2 [ j ] ) {
                res = max ( res , j - i ) ;
                j ++ ;
            }
            else i ++ ;
        }
        return res;
    }
};