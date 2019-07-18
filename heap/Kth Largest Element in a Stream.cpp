/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/
class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size=0;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto& n:nums){
            pq.push(n);
            if(pq.size()>size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
