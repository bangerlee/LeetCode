/*
https://leetcode.com/problems/flower-planting-with-no-adjacent/

*/
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> graph(N);
        for(vector<int>& p:paths){
            graph[p[0]-1].push_back(p[1]-1);
            graph[p[1]-1].push_back(p[0]-1);
        }
        for(int i=0;i<N;i++){
            vector<int> colors(5,0);
            for(int j:graph[i]) colors[res[j]]=1;
            for(int c=4;c>0;--c)
                if(!colors[c]){
                    res[i]=c;
                    break;
                }
        }
        return res;
    }
};
