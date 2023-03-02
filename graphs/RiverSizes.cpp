int get_river_size(std::vector<std::vector<int>>& matrix, int row, int col)
{
  const auto rows_size = matrix.size();
  const auto cols_size = matrix[0].size();  
  if (row < 0 || row >= rows_size || col < 0 || col >= cols_size || matrix[row][col] != 1)
    return 0;

  matrix[row][col] = 2;
  return 1 + get_river_size(matrix, row + 1, col) +
    get_river_size(matrix, row - 1, col) +
    get_river_size(matrix, row, col + 1) +
    get_river_size(matrix, row, col - 1);
}

// O(n * m) time / O(n + m) space
std::vector<int> riverSizes(std::vector<std::vector<int>>& matrix)
{
  std::vector<int> result;
  const auto rows_size = matrix.size();
  const auto cols_size = matrix[0].size();
  for (int row = 0; row < rows_size; ++row) {
    for (int col = 0; col < cols_size; ++col) {
      if (matrix[row][col] == 1) {
        const auto size = get_river_size(matrix, row, col);
        result.push_back(size);
      }
    }
  }

  return result;
}