/*
https://leetcode.com/problems/rabbits-in-forest/
*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(int x:answers) m[x]++;
        auto it=m.begin();
        int res=0;
        while(it!=m.end()){
            res+=(it->first+it->second)/(it->first+1)*(it->first+1);
            it++;
        }
        return res;
    }
};
