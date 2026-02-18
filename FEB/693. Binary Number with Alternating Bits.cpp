// 3 appraoches :


//1. we can convert the number to binary and check if the bits are alternating or not
//T.C : O(logn)
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=-1;
        while(n!=0){
            int cur =n%2;
            if(prev==cur)return false;
            prev=cur;
            n/=2;
        }
        return true;
    }
};
//2 we use bitset in c++ to convert the number to binary and find the largest set bit by log2(n) and then check if the bits are alternating or not by traversing the bits from the largest set bit to 0
//T.C : O(logn)
//S.C : O(32) => O(1)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32>b(n);
        int l=log2(n);
        for(int i=0;i<l;i++){
            if(b[i]==b[i+1])return false;
        }
        return true;
    }
};





// appraoch 3 : we can use the property of numbers with alternating bits that if we right shift the number by 1 and then XOR it with the original number then we will get a number which has all the bits set from the largest set bit to 0 and then we can check if the number is of the form 2^n - 1 or not by checking if (res & (res + 1)) == 0
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long res=n^(n>>1);
        return (res&(res+1))==0;
    }
};
