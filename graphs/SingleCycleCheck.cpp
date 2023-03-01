int getNextIdx(const vector<int>& array, int current_idx)
{
  const auto jump = array[current_idx];
  auto next_idx = current_idx + jump;
  while (next_idx < 0)
    next_idx += array.size();
  while (next_idx >= array.size())
    next_idx -= array.size();

  return next_idx;
}

// O(n) time / O(1) space
bool hasSingleCycle(const vector<int>& array) {
  auto current_idx = 0;
  auto number_visited = 0;
  while (number_visited < array.size()) {
    if (number_visited > 0 && current_idx == 0)
      return false;

    ++number_visited;
    current_idx = getNextIdx(array, current_idx);
  }
  
  return current_idx == 0;
}