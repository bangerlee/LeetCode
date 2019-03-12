/*
https://leetcode.com/problems/satisfiability-of-equality-equations/

*/
class Solution {
private:
    int find(vector<int>& v,int i){
        if(v[i]==-1||v[i]==i) return i;
        return find(v,v[i]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> v(26,-1);
        for(auto equation:equations){
            if(equation[1]=='='){
                int x=find(v,equation[0]-'a');
                int y=find(v,equation[3]-'a');
                v[x]=y;
            }
        }
        for(auto equation:equations){
            if(equation[1]=='!'){
                int x=find(v,equation[0]-'a');
                int y=find(v,equation[3]-'a');
                if(x==y) return false;
            }
        }
        return true;
    }
};
