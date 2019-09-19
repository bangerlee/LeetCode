/*
https://leetcode.com/problems/reconstruct-itinerary/

*/
class Solution {
private:
    void visit(string airport,vector<string>& res,unordered_map<string,multiset<string>>&m){
        while(m[airport].size()>0){
            string next=*m[airport].begin();
            m[airport].erase(m[airport].begin());
            visit(next,res,m);
        }
        res.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string,multiset<string>> m;
        for(auto ticket:tickets){
            m[ticket.first].insert(ticket.second);
        }
        visit("JFK",res,m);
        return vector<string>(res.rbegin(),res.rend());
    }
};
