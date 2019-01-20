/*
https://leetcode.com/problems/daily-temperatures/

*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(),0);
        for(int i=T.size()-2;i>=0;i--){
            if(T[i+1]>T[i]){
                res[i]=1;
                continue;
            }
            int j=i+1+res[i+1];
            while(j<T.size()&&T[j]<=T[i])
                j=res[j]==0?T.size():j+res[j];
            if(j>=T.size()) continue;
            res[i]=j-i;
        }
        return res;
    }
};
