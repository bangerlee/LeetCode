/*
https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

*/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> count;
        int res=0;
        for(int x:deck) count[x]++;
        for(auto it=count.begin();it!=count.end();it++)
            res=__gcd(res,it->second);
        return res>1;
    }
};
