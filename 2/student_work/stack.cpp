#include "stack.hpp"
#include "work.hpp"
#include <exception>
#include <stdexcept>

#include <algorithm>

namespace stack {

Stack::Stack(unsigned size) : Stack() {
  this->size = size;
  this->data = new Work[size];
}

Stack::Stack(unsigned size, unsigned data_size, Work *data) : Stack(size) {
  if (size < data_size)
    throw std::invalid_argument("Data size is greater than size of stack.");
  if (data == nullptr)
    throw std::invalid_argument("Array has not any data inside.");
  this->top = data_size;
  std::copy(data, data + data_size, this->data);
}

Stack::Stack(const Stack &other) {
  this->size = other.size;
  this->top = other.top;

  this->data = new Work[other.size];
  std::copy(other.data, other.data + other.top, this->data);
}

Stack::Stack(Stack &&other) noexcept {
  this->size = other.size;
  this->top = other.top;
  delete[] this->data;
  this->data = nullptr;
  this->data = other.data;

  other.size = MIN_SIZE;
  other.top = MIN_TOP;
  other.data = nullptr;
}

int find_index(Work *data, unsigned low_edge, unsigned high_edge,
               Work &cheking) {
  int found_index = -1;
  for (unsigned i = low_edge; i < high_edge; i++) {
    if (data[i].get_name() == cheking.get_name()) {
      found_index = i;
      return found_index;
    }
  }
  return found_index;
}

bool compare(const Work &a, const Work &b) { return a < b; }

void Stack::summ_all() {
  if (is_empty())
    throw std::logic_error("Can not summ in empty stack");
  Stack local{this->size};
  std::sort(this->data, this->data + this->top, compare);

  for (unsigned i = 0; i < this->top; i++) {
    /*int found_index = find_index(local.data, 0, local.top, this->data[i]);
    if (found_index == -1)
      local += this->data[i];
    else {
      if (local.data[found_index].can_add(this->data[i])) {
        local.data[found_index] = local.data[found_index] + this->data[i];
      } else {
        local += this->data[i];
      }
    }*/
    local += this->data[i];
  }

  *this = local;
}

void Stack::split_all() {
  if (is_empty())
    throw std::logic_error("Can not split in empty stack");
  unsigned number_of_all_pages = 0;
  for (unsigned i = 0; i < this->top; i++)
    number_of_all_pages += this->data[i].get_number_of_pages();
  Stack local{number_of_all_pages};

  for (unsigned i = 0; i < this->top; i++) {
    Work *splited_i = this->data[i].split();
    for (unsigned j = 0; j < this->data[i].get_number_of_pages(); j++) {
      local += splited_i[j];
    }
    delete[] splited_i;
  }

  *this = local;
}

Work Stack::pop() {
  if (is_empty())
    throw std::logic_error("Stack is empty.");
  Work result = this->data[--this->top];
  return result;
}

Work Stack::pop_without_mark() {
  if (is_empty())
    throw std::logic_error("Stack is empty.");
  Work result;
  for (int i = (int)this->top - 1; i >= 0; i--) {
    if (this->data[i].get_mark() == NO_MARK) {
      result = this->data[i];
      this->top--;

      for (unsigned j = (unsigned)i; j < this->top - 1; j++) {
        this->data[j] = this->data[j + 1];
      }
      return result;
    }
  }
  return result;
}

Stack &Stack::operator+=(const Work &new_work) {
  if (is_full())
    throw std::logic_error("Stack is overflow.");

  this->data[this->top] = new_work;
  this->top++;
  return *this;
}

Stack &Stack::operator=(const Stack &other) {
  if (this != &other) {
    Work *local = new Work[other.size];
    this->size = other.size;
    this->top = other.top;
    delete[] this->data;
    this->data = nullptr;
    this->data = local;
    std::copy(other.data, other.data + other.top, this->data);
  }
  return *this;
}

Stack &Stack::operator=(Stack &&other) noexcept {
  if (this != &other) {
    delete this->data;
    this->data = other.data;
    this->size = other.size;
    this->top = other.top;

    other.data = nullptr;
    other.size = 0;
    other.top = 0;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &stream, const Stack &stack) {
  stream << stack.size << " " << stack.top << "\n";
  for (unsigned i = 0; i < stack.top; i++)
    stream << stack.data[i] << "\n";
  return stream;
}

std::istream &operator>>(std::istream &stream, Stack &stack) {
  unsigned size = MIN_SIZE, top = MIN_TOP;
  stream >> size >> top;

  if (stream.good()) {
    if (size >= top) {
      stack.size = size;
      stack.top = top;
      if (stack.data)
        delete[] stack.data;
      stack.data = new Work[size];

      for (unsigned i = 0; i < top; i++) {
        stream >> stack.data[i];
      }
    } else
      stream.setstate(std::ios::failbit);
  }

  return stream;
}

} // namespace stack
