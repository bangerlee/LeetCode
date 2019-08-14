/*
https://leetcode.com/problems/3sum-with-multiplicity/

*/
class Solution {
private:
    const unsigned int M=1000000007;
public:
    int threeSumMulti(vector<int>& A, int target) {
        int len=A.size();
        long res=0;
        sort(A.begin(),A.end());
        for(int i=0;i<len-2;i++){
            int left=i+1,right=len-1;
            while(left<right){
                int tmp=A[i]+A[left]+A[right];
                if(tmp==target){
                    int l=1,r=1;
                    while(left+l<right&&A[left+l]==A[left]) l++;
                    while(left+l<=right-r&&A[right-r]==A[right]) r++;
                    res+=A[left]==A[right]?(right-left+1)*(right-left)/2:l*r;
                    left+=l,right-=r;
                }
                else if(tmp<target) left++;
                else right--;
            }
        }
        return res%M;
    }
};
