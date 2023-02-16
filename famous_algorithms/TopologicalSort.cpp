// O(e + d) time / O(e + d) space
std::vector<int> topologicalSort(std::vector<int> jobs, std::vector<std::vector<int>> deps)
{
  std::unordered_set<int> visited;
  std::unordered_set<int> visiting;
  std::unordered_map<int, std::vector<int>> graph;
  for (const auto& vertices: deps) {
    const auto from_vertex = vertices[0];
    const auto to_vertex = vertices[1];
    graph[from_vertex].push_back(to_vertex);
  }

  std::vector<int> result;
  std::function<bool(int)> impl;
  impl = [&impl, &graph, &visited, &visiting, &result] (int from_vertex) 
  {
    if (visited.count(from_vertex) != 0)
      return true;    
    if (visiting.count(from_vertex) != 0)
      return false;
    
    visiting.insert(from_vertex);
    for (const auto to_vertex: graph[from_vertex]) {
      const bool succeed = impl(to_vertex); 
      if (!succeed)
        return false;      
    }

    visited.insert(from_vertex);
    visiting.erase(from_vertex);
    result.push_back(from_vertex);
    return true;
  };

  for (const auto job: jobs) {
    const bool succeed = impl(job); 
    if (!succeed)
      return {};      
  }
  
  std::reverse(begin(result), end(result));
  return result;
}
