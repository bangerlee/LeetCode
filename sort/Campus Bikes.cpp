/*
https://leetcode.com/problems/campus-bikes/

*/
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int,int>>> buckets(2001);
        int n=workers.size(),m=bikes.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int dis=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                buckets[dis].push_back({i,j});
            }
        }
        vector<int> res(n,-1);
        vector<bool> bikeUsed(m,false);
        for(int d=0;d<=2000;d++){
            for(int k=0;k<buckets[d].size();k++){
                if(res[buckets[d][k].first]==-1 && !bikeUsed[buckets[d][k].second]){
                    bikeUsed[buckets[d][k].second]=true;
                    res[buckets[d][k].first]=buckets[d][k].second;
                }
            }
        }
        return res;
    }
};
