/*
https://leetcode.com/problems/find-the-town-judge/

*/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N+1,0);
        for(auto x:trust){
            count[x[0]]--,count[x[1]]++;
        }
        for(int i=1;i<=N;i++)
            if(count[i]==N-1) return i;
        return -1;
    }
};
