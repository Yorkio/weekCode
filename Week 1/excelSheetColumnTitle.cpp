class Solution {
    // n = sum_{i=0}^{columnName.len-1} (s[i] - 'A' + 1) * base^i
    // this solution uses simple mpdular algebra to restore each symbol
    
    const int base = 'Z' - 'A' + 1;
    
public:
    string convertToTitle(int n) {
        assert(n > 0);
        //if (n < 1) return "";
        vector<int> symbols;
        while (n) {
            --n;
            symbols.push_back(n % base + 'A');
            n /= base;
        }
        int len = symbols.size();
        string res(len, ' ');
        for (int i = 0; i < len; ++i) {
            res[i] = symbols[len - 1 - i];
        }
        return res;
    }
};

/* 
    Time complexity is O(ceil(log_base(n))).
    log_base(n) - can also be treated as upper bound for length of result.
    Memory complexity O(ceil(log_base(n))).
    Actually we can reduce constant in memory complexity by cancelling usage of symbols vector.
    But in this case we will have larger time complexity for concatenating strings.
    Which is according to http://www.cplusplus.com/reference/string/string/operator+/ can be linear in length of resulting string.

*/

/* 
    Questions:
    1. What is the alphabet we are working with?

*/

/*
    Tests:

    0

    1

    26
    
    27

*/
