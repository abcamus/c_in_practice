/* x的平方根
 *
 * https://leetcode.cn/problems/sqrtx/
 */
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid * mid > x) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }

        return ans;
    }
};