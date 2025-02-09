#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace matrix {

struct Matrix {
  unsigned rows_num = 0, cols_num = 0, vals_num = 0;
  unsigned *rows_indexes = nullptr;
  unsigned *cols_indexes = nullptr;
  float *values = nullptr;
};
Matrix input();
void output(const Matrix &matrix);
void remove(Matrix &matrix);

struct Vector {
  unsigned size = 0;
  float *data = nullptr;
};
Vector get_vector(const Matrix &sourse);
void output(const Vector &vector);
void remove(Vector &vector);

} // namespace matrix

#endif
