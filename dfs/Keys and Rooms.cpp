/*
https://leetcode.com/problems/keys-and-rooms/

*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> dfs;
        dfs.push(0);
        unordered_set<int> visited={0};
        while(!dfs.empty()){
            int idx=dfs.top();
            dfs.pop();
            for(int x:rooms[idx]){
                if(visited.count(x)==0){
                    dfs.push(x);
                    visited.insert(x);
                    if(visited.size()==rooms.size()) return true;
                }
            }
        }
        return visited.size()==rooms.size();
    }
};
