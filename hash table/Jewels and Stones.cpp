/*
https://leetcode.com/problems/jewels-and-stones/

*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s(J.begin(),J.end());
        int res=0;
        for(auto& k:S)
            if(s.count(k)) res++;
        return res;
    }
};
