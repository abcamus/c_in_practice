/* s=(1+n)*n/2 */
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = n;
        int ans;
        while (l <= r) {
            int mid = l + (r-l)/2;
            long long temp = (long long)(1+mid)*mid;
            if (temp > 2*(long long)n) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};