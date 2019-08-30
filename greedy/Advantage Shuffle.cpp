/*
https://leetcode.com/problems/advantage-shuffle/

*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.begin(),A.end());
        for(int i=0;i<B.size();i++){
            auto p=*s.rbegin()<=B[i]?s.begin():s.upper_bound(B[i]);
            A[i]=*p;
            s.erase(p);
        }
        return A;
    }
};
