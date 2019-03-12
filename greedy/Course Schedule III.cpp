/*
https://leetcode.com/problems/course-schedule-iii/

*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& a,vector<int>& b){
           return b[1]>a[1]; 
        });
        priority_queue<int> pq;
        int time=0;
        for(auto course:courses){
            time+=course[0];
            pq.push(course[0]);
            if(time>course[1]) time-=pq.top(),pq.pop();
        }
        return pq.size();
    }
};
