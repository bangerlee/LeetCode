/*
https://leetcode.com/problems/frog-jump/

*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size()==0) return true;
        unordered_map<int,unordered_set<int>> m;
        m[0].insert(1);
        for(int i=1;i<stones.size();i++)
            m[stones[i]].insert(0);
        for(int i=0;i<stones.size()-1;i++){
            int stone=stones[i];
            for(int step:m[stone]){
                int reach=stone+step;
                if(reach==stones[stones.size()-1]) return true;
                if(m.find(reach)!=m.end()){
                    m[reach].insert(step);
                    if(step-1>0) m[reach].insert(step-1);
                    m[reach].insert(step+1);
                }
            }
        }
        return false;
    }
};
