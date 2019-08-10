/*
https://leetcode.com/problems/high-five/

*/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        map<int,vector<int>> m;
        for(auto& v:items) m[v[0]].push_back(v[1]);
        for(auto& [id,v]:m){
            partial_sort(v.begin(),v.begin()+5,v.end(),greater<int>());
            res.push_back({id,(v[0]+v[1]+v[2]+v[3]+v[4])/5});
        }
        return res;
    }
};
