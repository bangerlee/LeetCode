/*
https://leetcode.com/problems/moving-average-from-data-stream/
*/
class MovingAverage {
private:
    long sum=0;
    int m_size=0;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_size=size;
    }
    
    double next(int val) {
        if(q.size()>=m_size){
            sum-=q.front();
            q.pop();
        }
        sum+=val;
        q.push(val);
        return double(sum)/double(q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
