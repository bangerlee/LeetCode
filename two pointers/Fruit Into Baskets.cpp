/*
https://leetcode.com/problems/fruit-into-baskets/

Runtime: 184 ms
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res=0;
        unordered_map<int,int> m;
        int i=0;
        for(int j=0;j<tree.size();j++){
            m[tree[j]]++;
            if(m.size()>2){
                m[tree[i]]--;
                if(m[tree[i]]==0) m.erase(tree[i]);
                i++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};
