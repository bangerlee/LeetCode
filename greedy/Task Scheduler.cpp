/*
https://leetcode.com/problems/task-scheduler/

*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        int m=0;
        for(auto& task:tasks){
            v[task-'A']++;
            m=max(v[task-'A'],m);
        }
        int res=(m-1)*(n+1);
        for(int i=0;i<26;i++){
            if(v[i]==m) res+=1;
        }
        return max(res,(int)tasks.size());
    }
};
