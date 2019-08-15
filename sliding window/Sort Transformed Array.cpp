/*
https://leetcode.com/problems/sort-transformed-array/

*/
class Solution {
private:
    int squr(int x,int a,int b,int c){
        return a*x*x+b*x+c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n=nums.size();
        vector<int> res(n);
        int idx=a>=0?n-1:0;
        int i=0,j=n-1;
        while(i<=j){
            int sq1=squr(nums[i],a,b,c);
            int sq2=squr(nums[j],a,b,c);
            if(a>=0){
                res[idx--]=sq1>sq2?sq1:sq2;
                sq1>sq2?i++:j--;
            }
            else{
                res[idx++]=sq1>sq2?sq2:sq1;
                sq1>sq2?j--:i++;
            }
        }
        return res;
    }
};
