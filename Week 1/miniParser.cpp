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
        return (ch >= '0' && ch <= '9' || ch == '-');
    }
    
    int getNext(int &pos, const string &s) {
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
        if (pos >= s.length()) return NestedInteger();
        if (s[pos] == ',') {
            ++pos;
            return process(s, pos);
        }
        if (isDigit(s[pos])) {
            int val = getNext(pos, s);
            return (NestedInteger(val));
        }
        NestedInteger root;
        ++pos;
        for ( ; pos < s.length() && s[pos] != ']'; ) {
            root.add(process(s, pos));
        } 
        if (s[pos] == ']') ++pos;
        return root;
    }
    
public:
    NestedInteger deserialize(string s) {
        int pos = 0, len = s.length();
        NestedInteger res;
        while (pos < len) {
            res = process(s, pos);
        }
        return res;    
    }
};
