#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <cstring>
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>
namespace utils {

template <class T> T input_num(const char *prompt) {
  std::cout << prompt << std::endl;
  T input_result;

  while (true) {
    std::cin >> input_result;
    if (std::cin.eof())
      throw std::runtime_error("Failed input: EOF");
    else if (std::cin.bad())
      throw std::runtime_error(std::string("Failed input: ") + strerror(errno));
    else if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input of number." << std::endl
                << " Try again! " << prompt;
    } else
      return input_result;
  }
}

template <class T> T *re_new(T *old_new, int old_size, int new_size) {
  T *new_new = new T[new_size]();
  if (old_size > new_size)
    std::copy(old_new, old_new + new_size, new_new);
  else
    std::copy(old_new, old_new + old_size, new_new);
  delete[] old_new;
  return new_new;
}

} // namespace utils

#endif
