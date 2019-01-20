/*
https://leetcode.com/problems/happy-number/

*/
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(s.insert(n).second){
            int sum=0;
            while(n!=0){
                int tmp=n%10;
                sum+=tmp*tmp;
                n=n/10;
            }
            if(sum==1)
                return true;
            else
                n=sum;
        }
        return false;
    }
};
