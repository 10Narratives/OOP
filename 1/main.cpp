#include <exception>
#include <iostream>
#include <new>

#include "matrix.hpp"

#include "utilities.hpp"
int main() {

  matrix::Matrix matrix{};
  matrix::Vector vector{};
  try {
    matrix = matrix::input();
    matrix::output(matrix);

    vector = matrix::get_vector(matrix);
    matrix::output(vector);

    matrix::remove(matrix);
    matrix::remove(vector);
  } catch (const std::bad_alloc &ba) {
    std::cout << "Not enough memory" << std::endl;
    matrix::remove(matrix);
    matrix::remove(vector);
    return 1;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    matrix::remove(matrix);
    matrix::remove(vector);
    return 1;
  }

  return 0;
}
