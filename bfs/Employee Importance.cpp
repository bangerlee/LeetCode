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
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res=0;
        unordered_map<int,Employee*> m;
        for(Employee* e:employees) m[e->id]=e;
        queue<Employee*> q;
        q.push(m[id]);
        while(!q.empty()){
            Employee* cur=q.front();q.pop();
            res+=cur->importance;
            for(auto s:cur->subordinates) q.push(m[s]);
        }
        return res;
    }
};
