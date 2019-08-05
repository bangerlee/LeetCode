/*
https://leetcode.com/problems/minimum-area-rectangle/

*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> x;
        int res=INT_MAX;
        for (auto p : points) x[p[0]].insert(p[1]);
        for (auto i = x.begin(); i != x.end(); ++i)
            for (auto j = next(i); j != x.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second),
                begin(j->second), end(j->second), back_inserter(y));
            for (int k = 1; k < y.size(); ++k)
            res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
        }
        return res == INT_MAX ? 0 : res;  
    }
};
