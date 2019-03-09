/*
https://leetcode.com/problems/expression-add-operators/

*/
class Solution {
private:
    void helper(vector<string>& res,string path,string& num,int& target,int pos,long eval,long multed){
        if(pos==num.length()){
            if(target==eval) res.push_back(path);
            return;
        }
        for(int i=pos;i<num.length();i++){
            if(i!=pos&&num[pos]=='0') break;
            long cur=stol(num.substr(pos,i-pos+1));
            if(pos==0) helper(res,path+to_string(cur),num,target,i+1,cur,cur);
            else{
                helper(res,path+"+"+to_string(cur),num,target,i+1,eval+cur,cur);
                helper(res,path+"-"+to_string(cur),num,target,i+1,eval-cur,-cur);
                helper(res,path+"*"+to_string(cur),num,target,i+1,eval-multed+multed*cur,multed*cur);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.length()==0) return res;
        helper(res,"",num,target,0,0,0);
        return res;
    }
};
