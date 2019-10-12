/*
https://leetcode.com/problems/array-of-doubled-pairs/

*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int,int> m;
        for(int x:A) m[x]++;
        vector<int> k;
        for(auto x:m) k.push_back(x.first);
        sort(k.begin(),k.end(),[](int a,int b){
            return abs(a)<abs(b);
        });
        for(int x:k){
            if(m[x]>m[2*x]) return false;
            m[2*x]-=m[x];
        }
        return true;
    }
};
