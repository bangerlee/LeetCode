/*
https://leetcode.com/problems/longest-harmonious-subsequence/

*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        int i=0;
        int max=0;
        for(;i<nums.size();i++){
            if(map.find(nums[i])==map.end())
                map[nums[i]]=1;
            else
                map[nums[i]]+=1;
        }
        unordered_map<int,int>::iterator it=map.begin();
        for(;it!=map.end();it++){
            int tmp=it->first;
            unordered_map<int,int>::iterator s=map.find(tmp-1);
            unordered_map<int,int>::iterator b=map.find(tmp+1);
            if(s!=map.end())
                if(it->second+s->second>max)
                    max=it->second+s->second;
            if(b!=map.end())
                if(it->second+b->second>max)
                    max=it->second+b->second;
                
        }
        return max;
    }
};
