/*
https://leetcode.com/problems/partition-labels/

*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v(26,0);
        vector<int> res;
        for(int i=0;i<S.size();i++) v[S[i]-'a']=i;
        int end=-1,i=0,begin=0;
        while(i<S.size()){
            end=max(v[S[i]-'a'],end);
            if(i==end){
                res.push_back(i-begin+1);
                begin=i+1;
            }
            i++;
        }
        return res;
    }
};
