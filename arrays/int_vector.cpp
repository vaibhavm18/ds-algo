#include "int__vector.hpp"
#include <cstddef>
#include <cstdio>
#include <new>

IntVector::IntVector() : data_(nullptr), size_(0), capacity_(0) {}

IntVector::IntVector(std::size_t initial_capacity)
    : data_(nullptr), size_(0), capacity_(0) {
  if (initial_capacity == 0)
    return;

  data_ = static_cast<int *>(::operator new(sizeof(int) * initial_capacity));

  capacity_ = initial_capacity;
}

IntVector::~IntVector() { ::operator delete(data_); }

std::size_t IntVector::size() const { return size_; }

std::size_t IntVector::capacity() const { return capacity_; }

void IntVector::reallocate() {
  std::size_t new_capacity = capacity_ == 0 ? 10 : capacity_ * 2;

  int *new_data =
      static_cast<int *>(::operator new(sizeof(int) * new_capacity));

  for (std::size_t i = 0; i < size_; i++) {
    new (new_data + i) int(data_[i]);
  }

  ::operator delete(data_);

  data_ = new_data;
  capacity_ = new_capacity;
}

void IntVector::push_back(int value) {
  if (size_ == capacity_) {
    reallocate();
  }
  new (data_ + size_) int(value);
  size_++;
}

void IntVector::print_vec() {
  for (std::size_t i = 0; i < size_; i++) {
    printf("%d-", data_[i]);
  }
}

int main() {
  IntVector v1;
  for (int i = 0; i < 20; i++) {
    v1.push_back(i * 4);
  }

  v1.print_vec();

  return 0;
}
