/*
https://leetcode.com/problems/reveal-cards-in-increasing-order/

*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        vector<int> res(deck.size());
        for(int i=0;i<deck.size();i++) q.push(i);
        for(int j=0;j<deck.size();j++){
            res[q.front()]=deck[j];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};
