#include <iostream>
#include <stdexcept>

#include "matrix.hpp"
#include "utilities.hpp"
using namespace utils;

namespace matrix {

void remove(Matrix &matrix) {
  delete[] matrix.rows_indexes;
  delete[] matrix.cols_indexes;
  delete[] matrix.values;
}

void set_val(Matrix &matrix, unsigned row, unsigned col, float value) {
  if (row > matrix.rows_num || col > matrix.cols_num)
    throw std::out_of_range("Row and col of new value is out of range");

  unsigned i, j;

  for (i = matrix.rows_indexes[row]; i < matrix.rows_indexes[row + 1]; i++) {
    if (matrix.cols_indexes[i] == col) {

      if (value) {
        matrix.values[i] = value;
        return;
      }

      for (j = i; j < matrix.rows_indexes[matrix.rows_num] - 1; j++) {
        matrix.values[j] = matrix.values[j + 1];
        matrix.cols_indexes[j] = matrix.cols_indexes[j + 1];
      }

      for (j = row + 1; j < matrix.rows_num + 1; j++)
        matrix.rows_indexes[j]--;
      return;
    }
  }

  if (!value)
    return;

  if (matrix.rows_indexes[matrix.rows_num] == matrix.vals_num)
    throw std::overflow_error("Matrix is overflow");

  for (j = matrix.rows_indexes[matrix.rows_num]; j > i; j--) {
    matrix.values[j] = matrix.values[j - 1];
    matrix.cols_indexes[j] = matrix.cols_indexes[j - 1];
  }

  matrix.cols_indexes[i] = col;
  matrix.values[i] = value;

  for (j = row + 1; j < matrix.rows_num + 1; j++)
    matrix.rows_indexes[j]++;

  return;
}

Matrix input() {
  Matrix new_matrix{};
  try {
    new_matrix.rows_num = input_num<unsigned>("Enter number of rows: ");
    new_matrix.cols_num = input_num<unsigned>("Enter number of cols: ");
    new_matrix.vals_num = input_num<unsigned>("Enter number of vals: ");
    while (new_matrix.rows_num * new_matrix.cols_num < new_matrix.vals_num) {
      std::cout << "Your values number is out of range. Try again!"
                << std::endl;
      new_matrix.vals_num = input_num<unsigned>("Enter number of vals: ");
    }

    new_matrix.rows_indexes = new unsigned[new_matrix.rows_num + 1];
    for (unsigned int i = 0; i < new_matrix.rows_num + 1; i++) {
      new_matrix.rows_indexes[i] = 0;
    }
    new_matrix.cols_indexes = new unsigned[new_matrix.vals_num];
    new_matrix.values = new float[new_matrix.vals_num];
    for (unsigned int i = 0; i < new_matrix.vals_num; i++) {
      new_matrix.cols_indexes[i] = 0;
      new_matrix.values[i] = 0;
    }

    for (unsigned int i = 0; i < new_matrix.vals_num; i++) {
      std::cout << "----------------------" << std::endl;
      unsigned new_row = input_num<unsigned>("Enter row of new val: ");
      unsigned new_col = input_num<unsigned>("Enter col of new val: ");
      float new_val = input_num<float>("Enter new val: ");
      set_val(new_matrix, new_row, new_col, new_val);
    }
    std::cout << "----------------------" << std::endl;

  } catch (...) {
    remove(new_matrix);
    throw;
  }
  return new_matrix;
}

float get_value(const Matrix &matrix, unsigned row, unsigned col) {
  for (unsigned i = matrix.rows_indexes[row]; i < matrix.rows_indexes[row + 1];
       i++) {
    if (matrix.cols_indexes[i] == col)
      return matrix.values[i];
  }
  return 0;
}

void output(const Matrix &matrix) {
  unsigned i, j;
  for (i = 0; i < matrix.rows_num; i++) {
    for (j = 0; j < matrix.cols_num; j++) {
      float value = get_value(matrix, i, j);
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
}

void remove(Vector &vector) {
  delete[] vector.data;
  vector.data = nullptr;
}

Vector get_vector(const Matrix &sourse) {
  Vector new_vector{};
  try {
    new_vector.size = sourse.rows_num;
    new_vector.data = new float[new_vector.size];
    for (unsigned int k = 0; k < new_vector.size; k++)
      new_vector.data[k] = 0;

    unsigned i, j;
    for (i = 0; i < sourse.rows_num; i++) {
      float summ = 0;

      for (j = 0; j < sourse.cols_num; j++) {
        float prev_value = 0;
        if (i == 0)
          prev_value = get_value(sourse, sourse.rows_num - 1, j);
        else
          prev_value = get_value(sourse, i - 1, j);
        float curr_value = get_value(sourse, i, j);
        if (curr_value > prev_value)
          summ += curr_value;
      }

      new_vector.data[i] = summ;
    }
  } catch (...) {
    remove(new_vector);
    throw;
  }
  return new_vector;
}

void output(const Vector &vector) {
  std::cout << "---------------------" << std::endl;
  for (unsigned int i = 0; i < vector.size; i++)
    std::cout << vector.data[i] << " ";
  std::cout << std::endl;
}

} // namespace matrix
