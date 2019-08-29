/*
https://leetcode.com/problems/queue-reconstruction-by-height/

*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.first>b.first||((a.first==b.first)&&b.second>a.second);
        });
        vector<pair<int,int>> res;
        for(auto x:people){
            res.insert(res.begin()+x.second,x);
        }
        return res;
    }
};
