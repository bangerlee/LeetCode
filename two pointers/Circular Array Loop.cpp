/*
https://leetcode.com/problems/circular-array-loop/

*/
class Solution {
private:
    int len=0;
    int advance(vector<int>& nums,int i){
        i+=nums[i];
        if(i<0) i=i%len+len;
        else if(i>len-1) i%=len;
        return i;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size()<2) return false;
        len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]==0) continue;
            int slow=i,fast=advance(nums,slow);
            while(nums[i]*nums[fast]>0 &&
                 nums[i]*nums[advance(nums,fast)]>0){
                if(slow==fast){
                    if(slow==advance(nums,slow)) break;
                    return true;
                }
                slow=advance(nums,slow);
                fast=advance(nums,advance(nums,fast));
            }
            slow=i;
            int sng=nums[i];
            while(sng*nums[slow]>0){
                int tmp=advance(nums,slow);
                nums[slow]=0;
                slow=tmp;
            }
        }
        return false;
    }
};
