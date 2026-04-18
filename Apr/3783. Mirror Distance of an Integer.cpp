/* Just do What the question asked
   Tc : o(W).  W: length of number 
   Sc : o(W)
*/

class Solution {
public:
    int revererse_Digit ( int n ) {
        string temp = to_string (n) ;
        reverse ( temp.begin() , temp.end() ) ;
        return stoi ( temp ) ;
    }
    int mirrorDistance(int n) {
        // edge case 
        if ( n < 10 ) return 0 ;
        int rev = revererse_Digit ( n ) ;
        return abs ( n - rev ) ;
    }
};