/*
https://leetcode.com/problems/image-overlap/

*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> la;
        vector<int> lb;
        int n=A.size();
        for(int i=0;i<n*n;i++) if(A[i/n][i%n]==1) la.push_back(i/n*100+i%n);
        for(int i=0;i<n*n;i++) if(B[i/n][i%n]==1) lb.push_back(i/n*100+i%n);
        unordered_map<int,int> count;
        for(auto i:la)
            for(auto j:lb)
                count[i-j]++;
        int res=0;
        auto it=count.begin();
        while(it!=count.end()){
            res=max(res,it->second);
            it++;
        }
        return res;
    }
};
