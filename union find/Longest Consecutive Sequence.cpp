/*
https://leetcode.com/problems/longest-consecutive-sequence/

*/
class UniFind{
private:
    vector<int> sz;
    vector<int> id;
public:
    UniFind(int n){
        for(int i=0;i<n;i++){
            sz.push_back(1);
            id.push_back(i);
        }
    }
    int find(int p){
        while(p!=id[p]){
            id[p]=id[id[p]];
            p=id[p];
        }
        return p;
    }
    void uni(int A,int B){
        int rootA=find(A);
        int rootB=find(B);
        if(rootA==rootB) return;
        if(sz[rootA]<sz[rootB]){
            sz[rootB]+=sz[rootA];
            id[rootA]=rootB;
        }
        else{
            sz[rootA]+=sz[rootB];
            id[rootB]=rootA;
        }
    }
    int maxSize(){
        return *max_element(sz.begin(),sz.end());
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        UniFind uf(nums.size());
        unordered_map<int,int> mapIndex;
        for(int i=0;i<nums.size();i++){
            if(mapIndex.count(nums[i])) continue;
            mapIndex[nums[i]]=i;
            if(mapIndex.count(nums[i]+1))
                uf.uni(i,mapIndex[nums[i]+1]);
            if(mapIndex.count(nums[i]-1))
                uf.uni(i,mapIndex[nums[i]-1]);
        }
        return uf.maxSize();
    }
};
