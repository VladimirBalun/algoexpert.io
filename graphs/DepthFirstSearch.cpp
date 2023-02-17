class Node {
public:
  std::string name;
  std::vector<Node*> children;

  explicit Node(std::string str)
    : name(str) {}

  // O(v + e) time / O(v) space
  std::vector<std::string> depthFirstSearch(std::vector<std::string>* array)
  {
    std::vector<std::string> result;
    std::function<void(Node*)> impl;
    impl = [&impl, &result] (Node* node)
    {
      if (!node)
        return;
      
      result.push_back(node->name);
      for (const auto child: node->children)
        impl(child);
    };

    impl(this);
    return result;
  }

  Node* addChild(std::string name)
  {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
