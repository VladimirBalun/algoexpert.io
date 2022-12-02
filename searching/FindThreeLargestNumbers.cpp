// O(n) time / O(1) space
std::vector<int> findThreeLargestNumbers(std::vector<int> array)
{
  int max_1 = std::numeric_limits<int>::min();
  int max_2 = std::numeric_limits<int>::min();
  int max_3 = std::numeric_limits<int>::min();
  
  for (const auto number: array) {
    if (number >= max_1) {
      max_3 = max_2;
      max_2 = max_1;
      max_1 = number;
    } else if (number >= max_2) {
      max_3 = max_2;
      max_2 = number;     
    } else if (number > max_3) {
      max_3 = number;   
    }
  }

  return { max_3, max_2, max_1 };
}
