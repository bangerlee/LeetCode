/*
https://leetcode.com/problems/largest-number/

Runtime: 16 ms
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        string res="";
        for(int c:nums)
            v.push_back(to_string(c));
        sort(v.begin(),v.end(),[](string& s1,string& s2){return s1+s2>s2+s1;});
        for(string b:v) res+=b;
        while(res.length()>1&&res[0]=='0') res=res.erase(0,1);
        return res;
    }
};
