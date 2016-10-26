class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //if (nums1.size() > nums2.size()) return intersection(nums2, nums1);

	// The idea here is to use some hash table data structure (set or map).
	// This table shows the presense of element in first array.	
	// Then while traversing 2nd array we update answer if given element is present in table(first array),
	// update table by removing current element. 

        vector<int> res;
        unordered_map<int, bool> exist;
        for (int i = 0; i < nums1.size(); ++i) {
            exist[nums1[i]] = true;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (exist.find(nums2[i]) != exist.end() && exist[nums2[i]]) {
                res.push_back(nums2[i]);
                exist[nums2[i]] = false;
            }
        }
        return res;
    }
};

/*
    nums1.size() = m, u - number of unique elements in nums1
    nums2.size() = n
    Time complexity T=O(max(m, n)) in average, worst case is T=O(m * max(m, n)).
    Memory complexity M = O(u)

*/

/*
    	[]
	[]

    	[1,2,3]
	[]

	[4]
	[1,2,3]
	
	[1,2,2,2,2,3,3,3,1]
	[1,2,5]	

*/
