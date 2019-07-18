/*
https://leetcode.com/problems/k-closest-points-to-origin/

*/
class Solution {
private:
    struct compare{
        bool operator()(vector<int>& p, vector<int>& q){
            return p[0]*p[0]+p[1]*p[1] < q[0]*q[0]+q[1]*q[1];
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(vector<int>& point : points){
            pq.push(point);
            if(pq.size()>K) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top());pq.pop();
        }
        return res;
    }
};
