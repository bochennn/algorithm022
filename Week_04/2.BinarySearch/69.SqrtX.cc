class Solution {
public:
  int mySqrt(int x) {
    // 牛顿迭代法
    // 求 y = x^2 - C = 0
    // 从x0开始,取该点切线方程: y = 2*x[i]*(x - x[i]) + (x[i]^2 - C)
    // 即 y = 2*xi*x - xi^2 - C 与x轴交点即为下次迭代值
    // => x[i+1] = (x[i]^2 + C) / (2*x[i])

    if (x == 0) {
      return 0;
    }

    double C = x, x0 = x;
    while (true) {
      double xi = 0.5 * (x0 + C / x0);
      if (fabs(x0 - xi) < 1e-7) {
        break;
      }
      x0 = xi;
    }
    return static_cast<int>(x0);

    // 二分查找法 套模版
    // long left = 0, right = x, res = -1;
    // while (left <= right) {
    //   int mid = left + (right - left) / 2;
    //  if (mid * mid <= x) {
    //    res = mid;
    //    left = mid + 1;
    //  } else {
    //    right = mid - 1;
    //  }
    //}
    //return static_cast<int>(ans);
  }

};
