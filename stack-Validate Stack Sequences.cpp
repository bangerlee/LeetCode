/*
https://leetcode.com/problems/validate-stack-sequences/

Runtime: 16 ms
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        for(int p : pushed){
            st.push(p);
            while(st.size()&&st.top()==popped[i]){
                st.pop();
                i++;
            }
        }
        return i==popped.size();
    }
};
