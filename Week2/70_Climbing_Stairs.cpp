class Solution {
public:
    int climbStairs(int n) {
	// We will use dp approach here.
	// To the i th level we can get either from i-1 or i-2 level, thus ways to get to ith is the sum of mentioned 2.
	// Initial state: 1 way to get to the 1st level, 1 way of getting to 0th level.
	// It is Fibonacci sequence.

        int curLevelWaysCount = 1, prevLevelWaysCount = 1;
        for (int level = 2; level <= n; ++level) {
            curLevelWaysCount += prevLevelWaysCount;
            prevLevelWaysCount = curLevelWaysCount - prevLevelWaysCount;
        }
        return curLevelWaysCount;
    }
};

/* 
	n - number of stair levels.
	Time Complexity T = O(n).
	Memory complexity M = O(n).

*/
