/*
https://leetcode.com/problems/line-reflection/

*/
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.size()<=1) return true;
        unordered_map<int,set<int>> m;
        int big=INT_MIN,small=INT_MAX;
        for(int i=0;i<points.size();i++){
            big=max(big,points[i].first);
            small=min(small,points[i].first);
            m[points[i].second].insert(points[i].first);
        }
        double line=(big+small)/2.0;
        for(auto it=m.begin();it!=m.end();it++){
            set<int>& s=it->second;
            for(auto start=s.begin(),end=s.end();start!=end;start++){
                if(((*start)+(*(--end)))/2.0!=line) return false;
                if(start==end) break;
            }
        }
        return true;
    }
};
