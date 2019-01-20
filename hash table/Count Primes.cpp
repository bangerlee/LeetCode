/*
https://leetcode.com/problems/count-primes/
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n,false);
        int res=0;
        for(int i=2;i<n;i++){
            if(v[i]==false) res++;
            for(int j=2;i*j<n;j++) v[i*j]=true;
        }
        return res;
    }
};
