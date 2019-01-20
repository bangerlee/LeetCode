/*
https://leetcode.com/problems/top-k-frequent-elements/
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        map<int,vector<int>> mv;
        vector<int> res;
        for(int x:nums) m[x]++;
        auto it=m.begin();
        while(it!=m.end()){
            mv[it->second].push_back(it->first);
            it++;
        }
        auto p=mv.end();
        p--;
        while(res.size()<k){
            for(int j=0;j<p->second.size()&&res.size()<k;j++)
                res.push_back(p->second[j]);
            p--;
        }
        return res;
    }
};
