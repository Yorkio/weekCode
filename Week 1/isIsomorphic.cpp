class Solution {
    const int alphSize = 256;
    
    bool check(const string &s, const string &t) {
        vector<int> mapping(alphSize, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (mapping[s[i]] == -1) {
                mapping[s[i]] = t[i];
            }    
            if (mapping[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);
    }
};

/*
Questions to interviewer:
1. Are we guaranteed to have strings of equal sizes?
2. What is the size of alphabet?

*/

/*
Test cases:

""
""

"aabb"
"tttt"

*/

/*
Time complexity is O(|s|).
Memory complexity is O(|alphabet|).

*/
