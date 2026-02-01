#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/* extern declarations */
extern void bubble_sort(vector<int> &);
extern void insertion_sort(vector<int> &);
extern void selection_sort(vector<int> &);
extern void merge_sort(vector<int> &, int, int);
extern void quick_sort(vector<int> &, int, int);

void print(const vector<int> &v) {
  for (int x : v)
    cout << x << " ";
  cout << "\n";
}

int main() {
  srand(42);

  vector<int> data(70);
  for (int i = 0; i < 70; ++i)
    data[i] = rand() % 1000;

  cout << "\nOriginal Array:\n";
  print(data);

  {
    auto v = data;
    bubble_sort(v);
    cout << "\nBubble Sort:\n";
    print(v);
  }

  {
    auto v = data;
    insertion_sort(v);
    cout << "\nInsertion Sort:\n";
    print(v);
  }

  {
    auto v = data;
    selection_sort(v);
    cout << "\nSelection Sort:\n";
    print(v);
  }

  {
    auto v = data;
    merge_sort(v, 0, v.size() - 1);
    cout << "\nMerge Sort:\n";
    print(v);
  }

  {
    auto v = data;
    quick_sort(v, 0, v.size() - 1);
    cout << "\nQuick Sort:\n";
    print(v);
  }

  return 0;
}
