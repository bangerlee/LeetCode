/*
https://leetcode.com/problems/sliding-puzzle/

*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string start="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)
                start+=to_string(board[i][j]);
        }
        unordered_set<string> visited;
        vector<vector<int>> dirs={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int res=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string cur=q.front();q.pop();
                if(cur==target) return res;
                int zero=cur.find("0");
                for(int dir:dirs[zero]){
                    string next=cur;
                    swap(next[zero],next[dir]);
                    if(visited.count(next)) continue;
                    visited.insert(next);
                    q.push(next);
                }
            }
            res++;
        }
        return -1;
    }
};
