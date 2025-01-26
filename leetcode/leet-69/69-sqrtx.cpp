#include <cstdlib>

using namespace std;

class Solution {
public:
  long long mySqrt(long long n) {
    if (n <= 1)
      return n;
    long long half_n = n / 2;
    long long srqt = sqrtIndex(1, half_n + 1, n);
    return srqt;
  }

  long long sqrtIndex(long long start, long long end, long long target) {
    long long mid = start + (end - start) / 2;
    if (mid == target / mid)
      return mid;
    else if (mid * mid > target)
      return sqrtIndex(start, mid - 1, target);
    else if (mid * mid < target) {
      long long next = mid + 1;
      if (next * next > target)
        return mid;
      else if (next * next < target)
        return sqrtIndex(next, end, target);
      else
        return mid + 1;
    }
    return EXIT_FAILURE;
  }
};
