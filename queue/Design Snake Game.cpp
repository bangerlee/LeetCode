/*
https://leetcode.com/problems/design-snake-game/
*/
class SnakeGame {
private:
    int width,height;
    vector<vector<int>> foods;
    deque<pair<int,int>> snake;
    int food_index=0,score=0;
    unordered_set<int> snakecells;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        snake.emplace_front(0,0);
        snakecells.insert(0);
        this->width=width;
        this->height=height;
        foods=food;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto& head=snake.front();
        int x=head.first,y=head.second;
        if(direction=="U") x--;
        else if(direction=="D") x++;
        else if(direction=="L") y--;
        else if(direction=="R") y++;
        if(x<0||y<0||x>=height||y>=width) return -1;
        if(food_index<foods.size() && x==foods[food_index][0] && y==foods[food_index][1]){
            food_index++;
            score++;
        }
        else{
            auto& back=snake.back();
            snakecells.erase(back.first*width+back.second);
            snake.pop_back();
        }
        int ind=x*width+y;
        if(snakecells.find(ind)!=snakecells.end()) return -1;
        snake.emplace_front(x,y);
        snakecells.insert(ind);
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
