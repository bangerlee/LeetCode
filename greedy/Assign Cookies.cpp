/*
https://leetcode.com/problems/assign-cookies/

*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res=0,i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(;i<s.size();i++){
            if(j<g.size()&&s[i]>=g[j]){
                res++;
                j++;
            }
        }
        return res;
    }
};
