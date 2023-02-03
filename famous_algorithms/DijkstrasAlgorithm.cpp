int getVertexIdxWithMinDistance(const std::vector<int>& min_distances, const std::unordered_set<int>& visited)
{
  auto result_idx = -1;
  auto min_distance = std::numeric_limits<int>::max();
  for (int i = 0; i < min_distances.size(); ++i) {
    const auto value = min_distances[i];
    if (visited.count(i) > 0)
      continue;

    if (value <= min_distance) {
      min_distance = value;
      result_idx = i;
    }
  }

  return result_idx;
}    

// O(v^2 + e) / O(v) space
std::vector<int> dijkstrasAlgorithm(int start_idx, std::vector<std::vector<std::vector<int>>> edges)
{
  const auto vertices_size = edges.size();
  std::vector<int> min_distances(vertices_size, std::numeric_limits<int>::max());
  min_distances[start_idx] = 0;

  auto current_idx = start_idx;
  std::unordered_set<int> visited;
  while (visited.size() < vertices_size) {
    const auto vertex_idx = getVertexIdxWithMinDistance(min_distances, visited);
    visited.insert(vertex_idx);

    if (min_distances[vertex_idx] == std::numeric_limits<int>::max()) {
      min_distances[vertex_idx] = -1;
      continue;
    }

    for (const auto& edge: edges[vertex_idx]) {
      const auto idx = edge[0];
      const auto distance = edge[1] + min_distances[vertex_idx];
      if (distance < min_distances[idx]) 
        min_distances[idx] = distance;
    }
  }

  return min_distances;
}