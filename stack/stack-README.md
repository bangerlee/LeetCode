next-greater-element-ii

https://leetcode.com/problems/next-greater-element-ii/

Typical ways to solve circular array problems. Java solution.

The first typical way to solve circular array problems is to extend the original array to twice length, 2nd half has the same element as first half. Then everything become simple.
Naive by simple solution, just look for the next greater element directly. Time complexity: O(n^2).

public class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int max = Integer.MIN_VALUE;
        for (int num : nums) {
            max = Math.max(max, num);
        }
        
        int n = nums.length;
        int[] result = new int[n];
        int[] temp = new int[n * 2];
        
        for (int i = 0; i < n * 2; i++) {
            temp[i] = nums[i % n];
        }
        
        for (int i = 0; i < n; i++) {
            result[i] = -1;
            if (nums[i] == max) continue;
            
            for (int j = i + 1; j < n * 2; j++) {
                if (temp[j] > nums[i]) {
                    result[i] = temp[j];
                    break;
                }
            }
        }
        
        return result;
    }
}
The second way is to use a stack to facilitate the look up. First we put all indexes into the stack, smaller index on the top. Then we start from end of the array look for the first element (index) in the stack which is greater than the current one. That one is guaranteed to be the Next Greater Element. Then put the current element (index) into the stack.
Time complexity: O(n).

public class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            stack.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            result[i] = -1;
            while (!stack.isEmpty() && nums[stack.peek()] <= nums[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()){
                result[i] = nums[stack.peek()];
            }
            stack.add(i);
        }
        
        return result;
    }
}

----
https://leetcode.com/problems/remove-duplicate-letters/

I think this solution is really concise! But I want to add some detailed explainations to show why we do so to solve the problem, This problem is in fact similiar to the problem "Largest Rectangle under the histogram "

We need to keep the monotically decreasing substring that contains all the char in the s. So we just use a vector to mimic the stack! Just similiar to the previous many solutions that use the vector to simulate a stack.

In fact this problem is also similiar to the problem that the maximum in the sliding windows, I strongly recommend you to grasp the sliding windows solutions.

Here is the AC C++ implementation

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0);
        vector<bool> visited(256, false);
        for(auto ch : s)  dict[ch]++;
        string result = "0";
        /** the key idea is to keep a monotically increasing sequence **/
        for(auto c : s) {
            dict[c]--;
            /** to filter the previously visited elements **/
            if(visited[c])  continue;
            while(c < result.back() && dict[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result.substr(1);
    }
};
