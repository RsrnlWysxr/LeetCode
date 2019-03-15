/* 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0 */

#include <vector>

using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) // 确保i在较长的区间内搜索
        {
            swap(n, m);
            swap(nums1, nums2);
        }

        int i, j, half_len; // i,j分别区分两个数组区间
        half_len = (m + n + 1) / 2;
        int imin = 0,
            imax = m;
        while (imin <= imax)
        {
            i = (imax + imin) / 2;
            j = half_len - i; // 确保了左右两侧长度一致
            if (i < imax && nums2[j - 1] > nums1[i]) // i太小
                imin = i + 1;
            else if (i > imin && nums1[i - 1] > nums2[j]) // i太大
                imax = i - 1;
            else // i刚好
            {
                double leftMax = 0;
                if (i == 0)
                    leftMax = nums2[j - 1];
                else if (j == 0)
                    leftMax = nums1[i - 1];
                else
                    leftMax = max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1)
                    return leftMax;

                double rightMin = 0;
                if (i == m)
                    rightMin = nums2[j];
                else if (j == n)
                    rightMin = nums1[i];
                else
                    rightMin = min(nums1[i], nums2[j]);

                return (leftMax + rightMin) / 2;
            }
        }
        return 0;
    }
};