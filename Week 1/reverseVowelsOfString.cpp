class Solution {
    
    // check if given symbol is vowel part is hardcoded
    // we can also use some sort of set
    // then we need to initialise it and time complexity will raise (will not grow if we'll go for hash set)
    // another possibility is to use bitvector for whole alphabet 
    // this case time complexity will stay unchanged, but memory usage will grow
    
    bool isVowel(char ch) {
        ch = tolower(ch);
        bool res = 0; 
        res |= (ch == 'a');
        res |= (ch == 'e');
        res |= (ch == 'i');
        res |= (ch == 'o');
        res |= (ch == 'u');
        return res;
    }
    
public:
    string reverseVowels(string s) {
        int len = s.length();
        string res = s; // O(|s|)
        
        //two pointers traversal through string and swapping all vowels 
        for (int i = 0, j = len - 1; i < j; ) {
            if (isVowel(res[i]) && isVowel(res[j])) {
                swap(res[i], res[j]);
                ++i;
                --j;
                continue;
            }
            if (!isVowel(res[i])) ++i;
            if (!isVowel(res[j])) --j;
        }
        
        return res;
    }
};

/*
    Questions:
    1. How should we deal with vowels?

*/

/* 
    Time complexity O(|s|)
    Memory complexity O(1), memory used for res is omitted.

*/

/*
    Tests:

    ""

    "aeiou"

    "     "

    "123|Scsc&QWcWC^evDV"

*/