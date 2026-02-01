#include <algorithm>
#include <vector>

int partition(std::vector<int> &nums, int low, int high) {
  int pivot = nums[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (nums[j] <= pivot) {
      i++;
      std::swap(nums[i], nums[j]);
    }
  }

  std::swap(nums[i + 1], nums[high]);
  return i + 1;
}

void quick_sort(std::vector<int> &nums, int low, int high) {
  if (low >= high)
    return;
  int pi = partition(nums, low, high);

  quick_sort(nums, low, pi - 1);
  quick_sort(nums, pi + 1, high);
}
