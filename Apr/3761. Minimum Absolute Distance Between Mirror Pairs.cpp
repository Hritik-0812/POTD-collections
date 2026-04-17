class Solution {
public:
    int Reverse_Digit ( int numb ) {
        string s = to_string( numb ) ;
        reverse( s.begin() , s.end() ) ;
        return stoi( s ) ;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map < int , int > mpp ;
        int ans = INT_MAX ;
        int n = nums.size() ;
        for( int i = 0 ; i < n ; i++ ) {
            int ele = nums[ i ] ;
            if ( mpp.find( ele ) != mpp.end() ){
                ans = min( ans , abs( i - mpp[ ele ] ) ) ;
            }
            mpp[ Reverse_Digit( ele ) ] = i;
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};