/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

*/
class Solution {
public:
    int minAddToMakeValid(string S) {
         int left=0,right=0;
        for(char& c:S){
            if(right==0&&c==')') left++;
            else right+=(c=='('?1:-1);
        }
        return left+right;
    }
};
