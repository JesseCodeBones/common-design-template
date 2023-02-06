#include <iostream>
#include <memory>
#include <stack>

struct treeNode{
    char value;
    treeNode* leftNode;
    treeNode* rightNode;
    treeNode(char c):value(c){}
};

void postOrderTraversal(treeNode *root) {
  if (root == nullptr) return;
  std::stack<treeNode*> stack;
  treeNode *current = root;
  treeNode *lastVisited = nullptr;
  while (current != nullptr || !stack.empty()) {
    while (current != nullptr) {
      stack.push(current);
      current = current->leftNode;
    }
    treeNode *node = stack.top();
    if (node->rightNode == nullptr || node->rightNode == lastVisited) {
      std::cout << node->value << ' ';
      lastVisited = node;
      stack.pop();
    } else {
      current = node->rightNode;
    }
  }
}

int main(int, char**) {
    treeNode ANode('A'), b('B'), c('C'), d('D'), e('E'), f('F');
    ANode.leftNode = &c;
    c.leftNode = &b;
    c.rightNode = &d;
    ANode.rightNode = &e;
    e.leftNode = &f;

    postOrderTraversal(&ANode);
    
    return 0;
}
