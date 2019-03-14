/*
https://leetcode.com/problems/accounts-merge/

*/
class Solution {
private:
    string find(unordered_map<string,string>& parent,string s){
        //path compression
        if(parent[s]!=s) parent[s]=find(parent,parent[s]);
        return parent[s];
        //return parent[s]==s?s:find(parent,parent[s]);
        //while(s!=parent[s]){
        //    parent[s]=parent[parent[s]];
        //    s=parent[s];
        //}
        //return s;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> owner;
        unordered_map<string,string> parent;
        unordered_map<string,set<string>> unions;
        vector<vector<string>> res;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                parent[accounts[i][j]]=accounts[i][j];
                owner[accounts[i][j]]=accounts[i][0];
            }
        }
        for(int i=0;i<accounts.size();i++){
            string p=find(parent,accounts[i][1]);
            for(int j=2;j<accounts[i].size();j++)
                parent[find(parent,accounts[i][j])]=p;
        }
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++)
                unions[find(parent,accounts[i][j])].insert(accounts[i][j]);
        }
        for(pair<string,set<string>> p:unions){
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin(),owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};
