/*
https://leetcode.com/problems/distribute-candies/

*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for(int x:candies) s.insert(x);
        return min(candies.size()/2,s.size());
    }
};
