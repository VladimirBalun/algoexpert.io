// O(n + m) time / O(1) space
std::vector<int> searchInSortedMatrix(std::vector<std::vector<int>> matrix, int target)
{
  int row = 0;
  int col = matrix.front().size() - 1;
  while (row < matrix.size() && col >= 0) {
    if (matrix[row][col] > target) {
      --col;
    } else if (matrix[row][col] < target) {
      ++row;
    } else {
      return { row, col };
    }
  }

  return { -1, -1 };
}
