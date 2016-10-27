class Solution {
    int cntSmaller(const vector<int> &arr, int val) {
        int l = -1, r = arr.size();
        while (r - l > 1) {
            int mid = l + ((r - l) >> 1);
            if (arr[mid] > val) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return l + 1;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
	// Key idea - use binary search.
	// We know that answer lies somewhere in between matrix[0][0] and matrix[n - 1][n - 1] so we can do binary search on thise values.
	// Each iteration of binary search we will go through 1 dimension of our matrix and calculate number of smaller elements than current value.
	// If this number is bigger than k than move right bound.
	// Otherwise move left bound. 


        int n = matrix.size();
        int left = matrix[0][0] - 1, right = matrix[n - 1][n - 1] + 1;
        while (right - left > 1) {
            int mid = left + ((right - left) >> 1), cnt = 0;
            for (vector<int> &arr : matrix) {
                cnt += cntSmaller(arr, mid);
            }
            cout << cnt << " " << mid << endl;
            if (cnt < k) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        
        int cnt = 0;
        for (vector<int> &arr : matrix) {
            cnt += cntSmaller(arr, left);
        }
        if (cnt >= k) return left;
        
        return right;
    }
};

/*
	Time complexity T = O(n log n log D), where n - matrix size, D - difference between first and last element in sorted array.
	Memory complexity M = O(1).	

	
*/
