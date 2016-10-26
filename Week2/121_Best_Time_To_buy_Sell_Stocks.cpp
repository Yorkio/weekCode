class Solution {
    const int INF = INT_MAX;
    
public:
    int maxProfit(vector<int>& prices) {
        // We move from the beginning to the end with one for loop.
        // At each iteration we try to greedily update the answer.
        // We should also try to update minimum price - best time to buy stock.
        
        int ans = 0, curMinPr = INF;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - curMinPr);
            curMinPr = min(curMinPr, prices[i]);
        }
        return ans;
    }
};

/* 
    n - number of days. (size of prices array)
    Time complexity T = O(n).
    Space M = O(1).
    
*/

/*
    []
    
    [1325]
    
    [3,2,1,0]
    
    [-11, 232, 23]
    
*/
