/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    bool isDigit(char ch) {
        // Function to check if given symbol ch can be part of integer number (e.g. 234, -32, .. ).

        return (ch >= '0' && ch <= '9' || ch == '-');
    }
    
    int getNext(int &pos, const string &s) {
        // Given the position pos of first digit or sigh return integer
        // which endes before "\n", "," or "]" in the given string s.

        int res = 0, mult = 1;
        if (s[pos] == '-') {
            mult = -1;
            ++pos;
        }
        for ( ; pos < s.length() && isDigit(s[pos]); ++pos) {
            res = res * 10 + s[pos] - '0';
        }
        return res * mult;
    }
    
    NestedInteger process(const string &s, int &pos) {
        // This function recursively generates nested integer list.
        // If we are at symbol "," we can just skip it.
        // If we are at digit or "-" symbol we can get next integer and add it to current list.
        // If we are at "[" symbol this means that next nested integer is list and we should put all
        // next nested integers inside this till we met paired symbol "]".
        // Base of the recursion when pos is larger than length of given string s.
        
        if (pos >= s.length()) return NestedInteger();

        if (s[pos] == ',') {
            ++pos;
        }
        
        if (isDigit(s[pos])) {
            int val = getNext(pos, s);
            return (NestedInteger(val));
        }
        

	// Case when pos is >= than parse string s length is base case and we've checked it in the beginning.
	// Then we checked if symbol is comma or in number set = {'0', .. , '9', '-'}.
	// The only 2 cases which are left - {'[', ']'}.
	// By the problem statement we know that s is correct
 	// so it can only be ']'.

        NestedInteger root;
        ++pos;
        while(s[pos] != ']') {
            root.add(process(s, pos));
        } 

        ++pos;
        return root;
    }
    
public:
    NestedInteger deserialize(string s) {
        int pos = 0;
        return process(s, pos);    
    }
};


/*
    Input string length = len.
    Time complexity T=O(len) recursively visit each position of a string maximum once.
    Memory complexity M=O(len) for recursion calls.
    Run time = 22ms.    

*/ 
