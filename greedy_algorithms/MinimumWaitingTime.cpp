// O(n*log(n)) time / O(1) space
int minimumWaitingTime(std::vector<int> queries)
{
  if (queries.size() == 1)
    return 0;
  
  std::sort(begin(queries), end(queries));

  int waiting_time = 0;
  for (int i = 0; i < queries.size() - 1; ++i) {
    const int duration = queries[i];
    const int queries_left = queries.size() - i - 1;
    waiting_time += duration * queries_left;
  }

  return waiting_time;
}
