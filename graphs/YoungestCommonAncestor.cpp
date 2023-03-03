class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(std::vector<AncestralTree*> descendants);
};

int getDescendantDepth(AncestralTree* ancestor)
{
  int depth = 0;
  while (ancestor) {
    ancestor = ancestor->ancestor;
    ++depth;
  }

  return depth;
}

AncestralTree* backtrackAncestralTree(
  AncestralTree* lowerDescendant,
  AncestralTree* higherDescendant,
  int difference
) {
  while (difference > 0) {
    lowerDescendant = lowerDescendant->ancestor;
    --difference;
  }

  while (lowerDescendant != higherDescendant) {
    lowerDescendant = lowerDescendant->ancestor;
    higherDescendant = higherDescendant->ancestor;
  }

  return lowerDescendant;
}

// O(d) time / O(1) space
AncestralTree* getYoungestCommonAncestor(
  AncestralTree* topAncestor,
  AncestralTree* descendantOne,
  AncestralTree* descendantTwo
) {
  if (descendantOne == descendantTwo)
    return descendantOne;
  
  int depthOne = getDescendantDepth(descendantOne);
  int depthTwo = getDescendantDepth(descendantTwo);
  if (depthOne > depthTwo)
    return backtrackAncestralTree(descendantOne, descendantTwo, depthOne - depthTwo);
  else
    return backtrackAncestralTree(descendantTwo, descendantOne, depthTwo - depthOne);
}
