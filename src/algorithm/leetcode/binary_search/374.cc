/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    int pick;
    int guess(int num) {
        return num == pick ? 0 : (num > pick ? -1 : 1);
    }
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int ret;
        while (l <= r) {
            long long mid = ((long long)l + r) >> 1;
            int ans = guess(mid);
            if (ans == -1) {
                r = mid - 1;
            } else if (ans == 1) {
                l = mid + 1;
            } else {
                ret = mid;
                break;
            }
        }
        return ret;
    }
};