// problem link : https://leetcode.com/problems/furthest-point-from-origin/description/
/* 
  Tc : o(n)
  Sc : o(1)
*/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0 ;
        int extra = 0 ;
        for ( auto c : moves ) {
            if ( c == 'L' ) ans ++ ;
            else if ( c == 'R' ) ans -- ;
            else extra ++ ;
        }
        return abs ( ans ) + extra ;
    }
};