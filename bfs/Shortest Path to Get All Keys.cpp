/*
https://leetcode.com/problems/shortest-path-to-get-all-keys/

*/
class State{
public:
    int keys,i,j;
    State(int keys, int i, int j){
        this->keys=keys;
        this->i=i;
        this->j=j;
    }
};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x=-1,y=-1,m=grid.size(),n=grid[0].size(),imax=-1,res=0;
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char c=grid[i][j];
                if(c=='@'){
                    x=i,y=j;
                }
                if(c>='a' && c<='f') imax=max(imax,c-'a'+1);
            }
        }
        State* start=new State(0,x,y);
        queue<State*> q;
        unordered_set<string> visited;
        visited.insert("0 "+to_string(x)+" "+to_string(y));
        q.push(start);
        while(!q.empty()){
            int size=q.size();
            while(size-- > 0){
                State* cur=q.front();q.pop();
                if(cur->keys==(1<<imax)-1) return res;
                for(auto dir:dirs){
                    int i=cur->i+dir[0], j=cur->j+dir[1];
                    int keys=cur->keys;
                    if(i>=0 && i<m && j>=0 && j<n){
                        char c=grid[i][j];
                        if(c=='#') continue;
                        if(c>='a' && c<='f') keys |= 1<<(c-'a');
                        if(c>='A' && c<='F' && ((keys >> (c-'A'))&1)==0) continue;
                        string tmp=to_string(keys)+" "+to_string(i)+" "+to_string(j);
                        if(!visited.count(tmp)){
                            visited.insert(tmp);
                            q.push(new State(keys,i,j));
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
