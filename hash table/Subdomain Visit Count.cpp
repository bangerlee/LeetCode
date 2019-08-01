/*
https://leetcode.com/problems/subdomain-visit-count/

*/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string,int> m;
        for(string s:cpdomains){
            int pos=s.find(" ");
            int count=stoi(s.substr(0,pos));
            m[s.substr(pos+1)]+=count;
            for(int i=pos+1;i<s.size();i++)
                if(s[i]=='.') m[s.substr(i+1)]+=count;
        }
        for(auto& k:m) res.push_back(to_string(k.second)+" "+k.first);
        return res;
    }
};
