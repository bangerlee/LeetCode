/*
https://leetcode.com/problems/strobogrammatic-number-iii/

*/
class Solution {
private:
    vector<string> helper(int n,int m){
        if(n==0) return vector<string>{1,""};
        if(n==1) return vector<string>{"1","0","8"};
        vector<string> v=helper(n-2,m);
        vector<string> res;
        for(int i=0;i<v.size();i++){
            string tmp=v[i];
            if(n!=m) res.push_back("0"+tmp+"0");
            res.push_back("8"+tmp+"8");
            res.push_back("1"+tmp+"1");
            res.push_back("6"+tmp+"9");
            res.push_back("9"+tmp+"6");
        }
        return res;
    }
    bool compare(string s1,string s2){
        if(s1.length()>s2.length()) return false;
        else if(s1.length()<s2.length()) return true;
        for(int i=0;i<s1.length();i++){
            if(s1[i]>s2[i]) return false;
            else if(s1[i]<s2[i]) return true;
        }
        return true;
    }
public:
    int strobogrammaticInRange(string low, string high) {
        int res=0;
        vector<string> ans;
        for(int n=low.length();n<=high.length();n++){
            vector<string> v=helper(n,n);
            for(auto& s:v) ans.push_back(s);
        }
        for(string num:ans){
            if(compare(low,num)&&compare(num,high))
                if(num.length()==1||(num.length()>1&&num[0]!='0')) res++;
        }
        return res;
    }
};
