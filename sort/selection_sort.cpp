

#include <algorithm>
#include <vector>
/*
 * Select a biggest number in
 * */
void selection_sort(std::vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (nums[min_index] > nums[j]) {
        min_index = j;
      }
    }
    std::swap(nums[i], nums[min_index]);
  }
}
