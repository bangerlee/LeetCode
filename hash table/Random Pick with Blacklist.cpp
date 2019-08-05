/*
https://leetcode.com/problems/random-pick-with-blacklist/

*/
class Solution {
private:
    int M;
    random_device rd;
    unordered_map<int,int> m;
public:
    Solution(int N, vector<int>& blacklist) {
        for(int& b:blacklist)
            m[b]=-1;
        M=N-m.size();
        for(int& b:blacklist){
            if(b<M){
                while(m.count(--N));
                m[b]=N;
            }
        }
    }
    
    int pick() {
        int res=rd()%M;
        if(m.count(res)) return m[res];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
