/*
https://leetcode.com/problems/combination-sum-iii/

*/
class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& tmp,int k,int n,int start){
        if(tmp.size()>k) return;
        if(start>10) return;
        if(accumulate(tmp.begin(),tmp.end(),0)>n) return;
        if(tmp.size()==k&&accumulate(tmp.begin(),tmp.end(),0)==n)
            res.push_back(tmp);
        else{
            for(int i=start;i<=9;i++){
                tmp.push_back(i);
                backtrack(res,tmp,k,n,i+1);
                vector<int>::iterator it=tmp.end();
                tmp.erase(it-1);
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res,tmp,k,n,1);
        return res;
    }
};
