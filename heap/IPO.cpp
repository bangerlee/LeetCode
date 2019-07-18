/*
https://leetcode.com/problems/ipo/
*/
class Solution {
private:
    struct compare1{
        bool operator()(const vector<int> a,const vector<int> b){
            return a[0]>b[0];
        }  
    };
    struct compare2{
        bool operator()(const vector<int> a,const vector<int> b){
            return b[1]>a[1];
        }
    };
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<vector<int>,vector<vector<int>>,compare1> pqCap;
        priority_queue<vector<int>,vector<vector<int>>,compare2> pqPro;
        for(int i=0;i<Profits.size();i++)
            pqCap.push({Capital[i],Profits[i]});
        for(int i=0;i<k;i++){
            while(!pqCap.empty() && pqCap.top()[0] <=W){
                pqPro.push(pqCap.top());pqCap.pop();
            }
            if(pqPro.empty()) break;
            W+=pqPro.top()[1];pqPro.pop();
        }
        return W;
    }
};
