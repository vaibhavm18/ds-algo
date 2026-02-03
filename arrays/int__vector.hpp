#pragma once

#include <cstddef>
class IntVector {
public:
  // constructor
  IntVector();
  explicit IntVector(std::size_t intital_capacity);

  // destructor RAII
  ~IntVector();

  // Non copyable
  IntVector(const IntVector &) = delete;
  IntVector &operator=(const IntVector &) = delete;

  // operations
  void push_back(int value);
  void print_vec();

  // helpers (read only)
  std::size_t size() const;
  std::size_t capacity() const;
  int *data() const;

private:
  void reallocate();

private:
  int *data_;
  std::size_t size_;
  std::size_t capacity_;
};
