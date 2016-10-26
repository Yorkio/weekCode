class Solution {
    const int maskFirstOne = (1 << 7);
    const int maxBytesNum = 4;
    
    int numLeadingOnes(int a) {
        int res = 0, findZero = 0;
        for (int mask = maskFirstOne; !findZero; mask >>= 1) {
            (mask & a) ? ++res : findZero = 1;
        }
        return res;
    }
    
    bool check(int pos, int cnt, const vector<int> &data) {
        int n = data.size();
        if (pos + cnt > n || !cnt) return false;
        for (int i = 0; i < cnt; ++i) {
            if (numLeadingOnes(data[i + pos]) != 1) return false;
        }
        return true;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; ) {
            int numLeadOnes = numLeadingOnes(data[i]);
            //assert(numLeadOnes < maxBytesNum + 1);
            if (!numLeadOnes) {
                ++i;
                continue;
            }
            if (!check(i + 1, numLeadOnes - 1, data)) return false;
            i += numLeadOnes;
        }
        return true;
    }
};
