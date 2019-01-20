/*
https://leetcode.com/problems/maximum-frequency-stack/
*/
class FreqStack {
private:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxfreq=0;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        maxfreq=max(maxfreq,++freq[x]);
        m[freq[x]].push(x);
    }
    
    int pop() {
        int res=m[maxfreq].top();
        m[maxfreq].pop();
        if(!m[freq[res]--].size()) maxfreq--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
