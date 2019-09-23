/*
https://leetcode.com/problems/employee-importance/

*/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
private:
    void helper(unordered_map<int,Employee*>& m,int id,int& sum){
        sum+=m[id]->importance;
        for(auto x:m[id]->subordinates) helper(m,x,sum);
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> m;
        for(auto x:employees) m[x->id]=x;
        int sum=0;
        helper(m,id,sum);
        return sum;
    }
};
