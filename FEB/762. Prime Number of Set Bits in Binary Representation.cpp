//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:

    /*
    approach : simply do what is said in the question (find the setbit of the every number in the 
    range of [left,right] check the numberof setbit is prime or not if it is the increment the count)

    tc: setbit :log(n) ~~ as int range the n can be maximum as 32 so log(32) ~5
        is_prime is callet for 0 To 32 max so its time complecity would underroot 32 ~~6
        for loop  N:right-left+1

        total :o(N) 

    sc: o(1)
    */

    bool is_prime(int n){
        if(n==1)return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            if(is_prime(__builtin_popcount(i)))count++;
        }
        return count;
    }
};


class Solution {
public:
    /* 
    approach: contraint highest value 10^6
    as we know 2^10 is 1024 if we square it both side we het 2^20 nearly about 10^6
    so maximum numbwr if set bits is 20 so instead of solving for is_prime repetatedly 
    instead store prime number 2 to 20 and check whethere it belong to that set or not

    tc:o(right-left+1)
    sc:o(1)
    */
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>st ={2,3,5,7,11,13,17,19};
        int count=0;
        for(int i=left;i<=right;i++){
            int n=__builtin_popcount(i);
            if(st.count(n))count++;
        }
        return count;
    }
};