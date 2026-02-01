

#include <algorithm>
#include <vector>
/*
 * Select a biggest number in
 * */
void selection_sort(std::vector<int> &nums) {
  size_t n = nums.size();
  for (size_t i = 0; i < n - 1; i++) {
    size_t min_index = i;
    for (size_t j = i + 1; j < n; j++) {
      if (nums[min_index] > nums[j]) {
        min_index = j;
      }
    }
    std::swap(nums[i], nums[min_index]);
  }
}
