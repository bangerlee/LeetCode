/*
https://leetcode.com/problems/the-skyline-problem/

*/
class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& v1,vector<vector<int>>& v2){
        vector<vector<int>> res;
        int h1=0,h2=0,i=0,j=0;
        while(i<v1.size()&&j<v2.size()){
            int x=0,h=0;
            if(v1[i][0]<v2[j][0]){
                x=v1[i][0];
                h1=v1[i][1];
                h=max(h1,h2);
                i++;
            }
            else if(v1[i][0]>v2[j][0]){
                x=v2[j][0];
                h2=v2[j][1];
                h=max(h1,h2);
                j++;
            }
            else{
                x=v1[i][0];
                h1=v1[i][1];
                h2=v2[j][1];
                h=max(h1,h2);
                i++,j++;
            }
            if(res.size()==0 || h!=res.back()[1])
                res.push_back({x,h});
        }
        while(i<v1.size()) res.push_back(v1[i++]);
        while(j<v2.size()) res.push_back(v2[j++]);
        return res;
    }
    vector<vector<int>> recurSkyline(vector<vector<int>>& buildings,int start,int end){
        if(start>=end){
            vector<vector<int>> v;
            v.push_back({buildings[start][0],buildings[start][2]});
            v.push_back({buildings[start][1],0});
            return v;
        }
        int mid=start+(end-start)/2;
        vector<vector<int>> v1=recurSkyline(buildings,start,mid);
        vector<vector<int>> v2=recurSkyline(buildings,mid+1,end);
        return merge(v1,v2);
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        if(buildings.size()==0) return res;
        return recurSkyline(buildings,0,buildings.size()-1);
    }
};
