/*
https://leetcode.com/problems/largest-values-from-labels/

*/
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<vector<int>> v;
        for(int i=0;i<values.size();i++){
            v.push_back({values[i],labels[i]});
        }
        sort(v.rbegin(),v.rend());
        unordered_map<int,int> cnt;
        int res=0,idx=0;
        while(num_wanted>0&&idx<v.size()){
            if(cnt[v[idx][1]]<use_limit){
                cnt[v[idx][1]]++;
                res+=v[idx][0];
                num_wanted--;
            }
            idx++;
        }
        return res;
    }
};
