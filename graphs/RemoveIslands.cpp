void dfs_impl(std::vector<std::vector<int>>& matrix, int row, int col, int value)
{
  const int rows_size = matrix.size();
  const int cols_size = matrix[0].size();  
  if (row < 0 || row >= rows_size || col < 0 || col >= cols_size || matrix[row][col] != 1)
    return;

  matrix[row][col] = value;
  dfs_impl(matrix, row + 1, col, value);
  dfs_impl(matrix, row - 1, col, value);
  dfs_impl(matrix, row, col + 1, value);
  dfs_impl(matrix, row, col - 1, value);
}

// O(n * m) time / O(n * m) space
std::vector<std::vector<int>> removeIslands(std::vector<std::vector<int>> matrix)
{
  const int rows_size = matrix.size();
  const int cols_size = matrix[0].size();
  for (int i = 0; i < cols_size; ++i) {
    if (matrix[0][i] == 1)
      dfs_impl(matrix, 0, i, 2);
    if (matrix[rows_size - 1][i] == 1)
      dfs_impl(matrix, rows_size - 1, i, 2);
  }

  for (int i = 0; i < rows_size; ++i) {
    if (matrix[i][0] == 1)
      dfs_impl(matrix, i, 0, 2);
    if (matrix[i][cols_size - 1] == 1)
      dfs_impl(matrix, i, cols_size - 1, 2);
  }

  for (int i = 0; i < rows_size; ++i) {
    for (int j = 0; j < cols_size; ++j) {
      if (matrix[i][j] == 1)
        matrix[i][j] = 0;
      if (matrix[i][j] == 2)
        matrix[i][j] = 1;
    }
  }
  
  return matrix;
}