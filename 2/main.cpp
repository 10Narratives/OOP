#include <exception>
#include <iostream>

#include "student_work/stack.hpp"
using namespace stack;

int main() {
  try {
    Stack s{10};
    Work a0{"A", 5, 1, 2};
    Work a00{"A", 5, 1, 2};
    Work a1{"A", 0, 3, 4};
    Work a2{"A", 0, 1, 3};
    Work a3{"A", 0, 4, 5};
    Work b0{"B", 5, 1, 2};
    Work b1{"B", 0, 3, 11};
    s += a1;
    s += a0;
    s += b1;
    s += b0;
    s += a2;
    s += a3;
    s += a00;
    std::cout << s << std::endl;
    s.summ_all();
    std::cout << s << std::endl;
  } catch (const std::bad_alloc &ba) {
    std::cout << "Not enough memory." << std::endl;
    return 1;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
