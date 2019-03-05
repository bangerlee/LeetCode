/*
https://leetcode.com/problems/walking-robot-simulation/

*/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<string> obs;
        for(auto v:obstacles){
            obs.insert(to_string(v[0])+" "+to_string(v[1]));
        }
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        int d=0,x=0,y=0,res=0;
        for(auto p:commands){
            if(p==-1){
                d++;
                if(d==4) d=0;
            }
            else if(p==-2){
                d--;
                if(d==-1) d=3;
            }
            else{
                while(p-->0&&obs.count(to_string(x+direction[d][0])+" "+to_string(y+direction[d][1]))==0){
                    x+=direction[d][0];
                    y+=direction[d][1];
                }
            }
            res=max(res,x*x+y*y);
        }
        return res;
    }
};
