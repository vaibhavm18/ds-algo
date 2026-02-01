#include <algorithm>
#include <vector>

void bubble_sort(std::vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    bool swap = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        std::swap(nums[j], nums[j + 1]);
        swap = true;
      }
    }
    if (!swap) {
      break;
    }
  }
}
