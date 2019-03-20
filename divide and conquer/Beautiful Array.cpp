/*
https://leetcode.com/problems/beautiful-array/

*/
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res{1};
        while(res.size()<N){
            vector<int> tmp;
            for(auto i:res) if(i*2-1<=N) tmp.push_back(i*2-1);
            for(auto i:res) if(i*2<=N) tmp.push_back(i*2);
            res=tmp;
        }
        return res;
    }
};
