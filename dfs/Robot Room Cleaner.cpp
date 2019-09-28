/*
https://leetcode.com/problems/robot-room-cleaner/

*/
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
private:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    void helper(Robot& robot,int x,int y,int curdir,unordered_set<string>& visited){
        visited.insert(to_string(x)+"#"+to_string(y));
        robot.clean();
        for(int i=0;i<dir.size();i++){
            int nextdir=(curdir+i)%4;
            int p=x+dir[nextdir][0],q=y+dir[nextdir][1];
            if(!visited.count(to_string(p)+"#"+to_string(q))&&robot.move()){
                helper(robot,p,q,nextdir,visited);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        helper(robot,0,0,0,visited);
    }
};
