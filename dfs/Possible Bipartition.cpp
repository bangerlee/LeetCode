/*
https://leetcode.com/problems/possible-bipartition/

*/
class Solution {
private:
    bool helper(vector<int>& group,vector<vector<int>>& graph,int idx,int color){
        group[idx]=color;
        for(int j=1;j<graph.size();j++){
            if(graph[idx][j]==1){
                if(color==group[j]) return false;
                if(group[j]==0&&!helper(group,graph,j,-color)) return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1,vector<int>(N+1,0));
        vector<int> group(N+1,0);
        for(auto dislike:dislikes){
            graph[dislike[0]][dislike[1]]=1;
            graph[dislike[1]][dislike[0]]=1;
        }
        for(int i=1;i<group.size();i++){
            if(group[i]==0&&!helper(group,graph,i,1)) return false;
        }
        return true;
    }
};
