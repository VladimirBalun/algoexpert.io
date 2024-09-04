// O(n*m) time / O(n*m) space
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix)
{
  const int rows_count = matrix.size();
  const int cols_count = matrix[0].size();

  std::vector<std::vector<int>> transposed(cols_count, std::vector<int>(rows_count));
  for (int col = 0; col < cols_count; ++col) {
    for (int row = 0; row < rows_count; ++row) {
      transposed[col][row] = matrix[row][col];
    }
  }
  
  return transposed;
}