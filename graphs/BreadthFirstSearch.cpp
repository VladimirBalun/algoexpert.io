class Node {
public:
  std::string name;
  std::vector<Node*> children;

  explicit Node(std::string str)
    : name(str) {}

  // O(v + e) time / O(v) space
  std::vector<std::string> breadthFirstSearch(std::vector<std::string>* array)
  {
    std::queue<Node*> queue;
    queue.push(this);

    while (!queue.empty()) {
      Node* node = queue.front();
      queue.pop();
      
      array->push_back(node->name);
      for (auto child: node->children)
        queue.push(child);
    }

    return *array;
  }

  Node *addChild(std::string name)
  {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};