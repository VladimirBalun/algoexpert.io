// O(n) time / O(1) space
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence)
{
  int array_idx = 0;
  int sequence_idx = 0;
  while (array_idx < array.size() && sequence_idx < sequence.size()) {
    const int array_value = array[array_idx];
    const int sequence_value = sequence[sequence_idx];
    if (array_value == sequence_value)
      ++sequence_idx;
    ++array_idx;
  }
  
  return sequence_idx == sequence.size();
}

// O(n) time / O(1) space
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence)
{
  int sequence_idx = 0;
  for (const int value: array) {
    if (sequence_idx == sequence.size())
      break;
    
    const int sequence_value = sequence[sequence_idx];
    if (value == sequence_value)
      ++sequence_idx;
  }

  return sequence_idx == sequence.size();
}
