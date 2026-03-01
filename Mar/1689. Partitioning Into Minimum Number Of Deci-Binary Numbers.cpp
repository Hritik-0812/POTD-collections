//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

class Solution {
public:
    int minPartitions(string n) {
        /*
        aproach brute force: take bigest number(i.e 111's) till n size and subtract it if you 
        get zeos avoid them do this process until string get converted into all 0's and 
        count the number of steps

        tc: max_digit*size
            o(9*S) ~~ o(n)/o(S)
        sc: o(1)
        */
        int ans = 0;
        bool flag=false;
        while(!flag){
            flag=true;
            for(int i=0;i<n.size();i++){
                int digit=n[i]-'0';
                if(digit>0){
                    n[i]=digit-1+'0';
                    flag=false;
                }
            }
            if(!flag)ans++;
        }
        return ans;
        
    }
};

class Solution {
public:
    /*
    aproach optimal : as in brute force we are taking bigest number and subtracting it from n 
    and counting the steps but we can observe that the bigest number we can take is 111's and 
    the number of 1's in that number is equal to the max digit in n so we can directly return 
    the max digit in n as the answer  

    tc: o(n)
    sc: o(1)
    */
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) ans = max(ans, c - '0');
        return ans;
    }
};