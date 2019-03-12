/*
https://leetcode.com/problems/strobogrammatic-number-ii/

*/
class Solution {
private:
    vector<string> helper(int n,int m){
        if(n==0) return vector<string>(1,"");
        if(n==1) return vector<string>{"0","1","8"};
        vector<string> v=helper(n-2,m);
        vector<string> res;
        for(int i=0;i<v.size();i++){
            string tmp=v[i];
            if(n!=m) res.push_back("0"+tmp+"0");
            res.push_back("1"+tmp+"1");
            res.push_back("8"+tmp+"8");
            res.push_back("6"+tmp+"9");
            res.push_back("9"+tmp+"6");
        }
        return res;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n,n);
    }
};
