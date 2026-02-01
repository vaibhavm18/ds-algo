#include <cstddef>
#include <vector>
void insertion_sort(std::vector<int> &nums) {
  std::size_t n = nums.size();
  if (n == 0 || n == 1)
    return;
  for (size_t i = 1; i < n; i++) {
    int current_element = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > current_element) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = current_element;
  }
}

/*
 * [3,2,4,5,6,7]
 * [8,7,6,5,4,3]
 * i = 1
 * so current element will be 1 index
 * and the j will be one less. so now we will loop until the left window is
 * sorted, for example [5,6,7,8, | 3,2] Here inedex  0,1,2,3    4,5 so now our i
 * will be 4 we will make its current element. now we will start inner loop from
 * 3 to 0. the thing is our left part of the array is already sorted. we just
 * need to place the current element only. In inner loop if current element is
 * bigger then we break the loop we will set +1 inner loop index to current
 * element. else we will swap inner loop + 1 index to current inner loop index.
 * like after complition of one iteration of inner loop [5,6,7,8, | 8,2]
 * in each loop it will brea
 * 1. [5,6,7,7,8,2]
 * 2. [5,6,6,7,8,2]
 * 3. [5,5,6,7,8,2]
 * now first two element are same so inner loop will break.
 * then we will current_element will be set to inner loop index + 1.
 * so [3,5,6,7,8,2]
 *
 * we will now stop looping outerloop until all elmenet are sorted.
 *
 * wort case senario is o(n*n)
 * */
