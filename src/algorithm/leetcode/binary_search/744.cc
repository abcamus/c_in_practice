/* https://leetcode.cn/problems/find-smallest-letter-greater-than-target/ */
#include "leetcode.h"

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (*letters.rbegin() < target || *letters.begin() > target) {
            return *letters.begin();
        }
        size_t l = 0;
        size_t r = letters.size() - 1;
        char cur = *letters.begin();

        while (l <= r) {
            size_t mid = l + (r-l) / 2;
            if (letters.at(mid) > target) {
                cur = letters.at(mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return cur;
    }
};

char nextGreatestLetter(vector<char>& letters, char target)
{
    Solution s;
    return s.nextGreatestLetter(letters, target);
}