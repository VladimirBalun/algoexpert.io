class BST {
public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

// O(n) time / O(n) space
int findKthLargestValueInBst(BST* tree, int k)
{
  std::vector<int> values;
  std::function<void(BST*)> impl;
  impl = [&impl, &values, k] (BST* node)
  {
    if (!node)
      return;
    
    impl(node->left);
    values.push_back(node->value);
    impl(node->right);
  };

  impl(tree);
  return values[values.size() - k];
}

// O(d + k) time / O(d) space
int findKthLargestValueInBst(BST* tree, int k)
{
  int visited_nodes = 0;
  int last_visited_node_value = -1;
  std::function<void(BST*)> impl;
  impl = [&impl, &visited_nodes, &last_visited_node_value, k] (BST* node)
  {
    if (!node || visited_nodes == k)
      return;

    impl(node->right);
    if (visited_nodes < k) {   
      last_visited_node_value = node->value;
      ++visited_nodes;
      impl(node->left);
    }
  };

  impl(tree);
  return last_visited_node_value;
}