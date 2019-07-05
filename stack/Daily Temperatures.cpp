/*
https://leetcode.com/problems/daily-temperatures/
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> monostack;
        vector<int> res(T.size(),0);
        for(int i=0;i<T.size();i++){
            while(!monostack.empty()&&T[i]>T[monostack.top()]){
                res[monostack.top()]=i-monostack.top();
                monostack.pop();
            }
            monostack.push(i);
        }
        return res;
    }
};
