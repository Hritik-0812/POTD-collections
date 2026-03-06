//https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/

//1 approach

class Solution {
public:
  /*
    approach : simply count the number of times we encounter the ones sequence if we encounter more than one sequence return false else true
    tc: o(n)
    sc: o(1)
    */
    bool checkOnesSegment(string s) {
        int count=0;
        int n=s.size()-1;
        for(int i=0;i<n;i++){
            if(s[i]!=s[i+1])count++;
            if(count>1)return false;
        }
        return true;
    }
};

// 2 approach 
class Solution {
public:
    /*
    approach : as given in the problem that string start with one so if we encounter any 01 in the string 
            it means it is start of the new sequence hence return false    
    tc: o(n)
    sc: o(1)
    */
    bool checkOnesSegment(string s) {
        int count=0;
        int n=s.size()-1;
        for(int i=0;i<n;i++){
            if((s[i]=='0') && (s[i+1]=='1'))return false;
        }
        return true;
    }
};