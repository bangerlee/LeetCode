/*
https://leetcode.com/problems/pancake-sorting/

*/
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for(int i=0;i<A.size();i++){
            auto m=max_element(A.begin(),A.end()-i);
            res.push_back(m-A.begin()+1);
            res.push_back(A.end()-A.begin()-i);
            reverse(A.begin(),m+1);
            reverse(A.begin(),A.end()-i);
        }
        return res;
    }
};
