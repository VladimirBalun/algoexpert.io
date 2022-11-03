class BST {
public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

// O(n^2) time / O(d) space
BST* reconstructBst(const std::vector<int>& pre_order_traversal_values)
{
  std::function<BST*(size_t, size_t)> impl;
  impl = [&impl, &pre_order_traversal_values] (size_t left, size_t right) -> BST*
  {
    if (left == right)
      return nullptr;

    size_t right_child_index = right;
    const auto current_value = pre_order_traversal_values[left];
    for (size_t i = left + 1; i < right; ++i) {
      if (pre_order_traversal_values[i] >= current_value) {
        right_child_index = i;
        break;
      }
    }

    auto node = new BST(current_value);
    node->left = impl(left + 1, right_child_index);
    node->right = impl(right_child_index, right);
    return node;
  };
  
  return impl(0, pre_order_traversal_values.size());
}

// O(n) time / O(d) space
BST* reconstructBst(const std::vector<int>& pre_order_traversal_values)
{
  std::function<BST*(int, int, size_t&)> impl;
  impl = [&impl, &pre_order_traversal_values] (int min, int max, size_t& root_idx) -> BST*
  {
    if (root_idx == pre_order_traversal_values.size())
      return nullptr;

    const auto root_value = pre_order_traversal_values[root_idx];
    if (root_value < min || root_value >= max)
      return nullptr;

    root_idx++;
    auto node = new BST(root_value);
    node->left = impl(min, root_value, root_idx);
    node->right = impl(root_value, max, root_idx);
    return node;
  };

  size_t root_idx = 0u;
  const auto min = std::numeric_limits<int>::min();
  const auto max = std::numeric_limits<int>::max();
  return impl(min, max, root_idx);
}
