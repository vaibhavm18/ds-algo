#include <vector>
void merge(std::vector<int> &nums, int l, int m, int r) {
  std::vector<int> left(nums.begin() + l, nums.begin() + m + 1),
      right(nums.begin() + m + 1, nums.begin() + r + 1);

  int i = 0, j = 0, k = l;
  while (i < left.size() && j < right.size()) {
    nums[k++] = (left[i] <= right[j] ? left[i++] : right[j++]);
  }
  while (i < left.size()) {
    nums[k++] = left[i++];
  }

  while (j < right.size()) {
    nums[k++] = right[j++];
  }
}
void merge_sort(std::vector<int> &nums, int l, int r) {
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  merge_sort(nums, l, m);
  merge_sort(nums, m + 1, r);
  merge(nums, l, m, r);
}
