/*
 * https://leetcode.cn/problems/valid-perfect-square/description/
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = num;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long temp = (long long)mid * mid;
            if (temp > num) {
                r = mid - 1;
            } else if (temp < num) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};