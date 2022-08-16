// O(n) time / O(1) space
int kadanesAlgorithm(std::vector<int> array)
{
  int max_sum = array[0];
  int current_sum = array[0];
  for (size_t i = 1u; i < array.size(); ++i) {
    current_sum = std::max(current_sum + array[i], array[i]);
    max_sum = std::max(max_sum, current_sum);
  }
  
  return max_sum;
}