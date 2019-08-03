/*
https://leetcode.com/problems/group-shifted-strings/

*/
class Solution {
private:
    string shift(string s){
        string res="";
        for(int i=1;i<s.length();i++){
            int diff=s[i]-s[i-1];
            diff=diff<0?diff+26:diff;
            res+='a'+diff+',';
        }
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(string x:strings)
            m[shift(x)].push_back(x);
        for(auto p:m){
            res.push_back(p.second);
        }
        return res;
    }
};
