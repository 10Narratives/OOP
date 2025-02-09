#ifndef STACK_HPP
#define STACK_HPP

#include "work.hpp"
#include <iostream>
#include <istream>
#include <ostream>
using namespace work;

namespace stack {

#define MIN_TOP 0
#define MIN_SIZE 0

class Stack {
private:
  unsigned size = MIN_SIZE, top = MIN_TOP;
  Work *data = nullptr;

public:
  Stack() = default;
  explicit Stack(unsigned size);
  Stack(unsigned size, unsigned data_size, Work *data);
  Stack(const Stack &other);
  Stack(Stack &&other) noexcept;
  ~Stack() { delete[] this->data; }

  void summ_all();
  void split_all();

  bool is_empty() const { return this->top == 0; }
  bool is_full() const { return this->top == this->size; }

  unsigned get_size() const { return this->size; }
  unsigned get_top() const { return this->top; }

  Work pop();
  Work pop_without_mark();

  Stack &operator+=(const Work &new_work);
  Stack &operator=(const Stack &ohter);
  Stack &operator=(Stack &&other) noexcept;
  friend std::ostream &operator<<(std::ostream &stream, const Stack &stack);
  friend std::istream &operator>>(std::istream &stream, Stack &stack);
};

} // namespace stack

#endif
