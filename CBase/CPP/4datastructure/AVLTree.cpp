#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <chrono>

template <typename T>
struct AVLNode
{
    T key;
    AVLNode *left_node;
    AVLNode *right_node;
    AVLNode *parent;

    int findHight()
    {
        int hight = 0;
        std::vector<AVLNode<T> *> vct;
        if (this == NULL)
        {
            return 0;
        }

        vct.push_back(this);
        while (!vct.empty())
        {
            AVLNode<T> *n = vct.back();
            vct.pop_back();
            // loop action
            int h = findDistance(this, n);
            if (h > hight)
            {
                hight = h;
            }
            // end loop action
            if (n->right_node != NULL)
            {
                vct.push_back(n->right_node);
            }
            if (n->left_node != NULL)
            {
                vct.push_back(n->left_node);
            }
        }
        return hight;
    }

    int balanceFactor()
    {
        int leftHight = this->left_node->findHight(), rightHight = this->right_node->findHight();
        if (this->left_node != NULL)
        {
            leftHight += 1;
        }

        if (this->right_node != NULL)
        {
            rightHight += 1;
        }

        return leftHight - rightHight;
    }

    void rotate(bool isRightRotate)
    {

        AVLNode<T> *parentParent = this->parent;
        bool replaceRight = true;
        if (this->parent->left_node == this)
        {
            replaceRight == false;
        }
        AVLNode<T> *newParentNode;
        if (isRightRotate)
        {

            newParentNode = this->left_node;
            this->left_node = newParentNode->right_node;
            if (newParentNode->right_node != NULL)
            {
                newParentNode->right_node->parent = this;
            }
            newParentNode->right_node = this;
            newParentNode->parent = this->parent;
            this->parent = newParentNode;
        }
        else
        {
            newParentNode = this->right_node;
            this->right_node = newParentNode->left_node;
            if (newParentNode->left_node != NULL)
            {
                newParentNode->left_node->parent = this;
            }
            newParentNode->left_node = this;
            newParentNode->parent = this->parent;
            this->parent = newParentNode;
        }

        if (parentParent != NULL)
        {
            if (replaceRight)
            {
                parentParent->right_node = newParentNode;
            }
            else
            {
                parentParent->left_node = newParentNode;
            }
        }
    }

    void __balanceTree(AVLNode<T> *node)
    {

        // 1, find unbalance node
        // 2, get LL, LR, RL, RR option
        char firstFlag = 'R';
        char secondFlag = 'R';
        if (node->parent->left_node == node)
        {
            secondFlag = 'L';
        }

        AVLNode<T> *cursor = node->parent;
        while (abs(cursor->balanceFactor()) <= 1 && cursor->parent != NULL)
        {
            cursor = cursor->parent;
        }
        if (abs(cursor->balanceFactor()) > 1)
        {                                    // need rebalance
            if (cursor->balanceFactor() > 0) // left hight > right hight
            {
                firstFlag = 'L';
            }
            // finish the flag adjustment
            // process for each condition
            std::string condition;
            condition.push_back(firstFlag);
            condition.push_back(secondFlag);
            if (condition.compare("LL") == 0)
            {
                cursor->rotate(true);
            }

            if (condition.compare("RR") == 0)
            {
                cursor->rotate(false);
            }

            if (condition.compare("LR") == 0)
            {
                cursor->left_node->rotate(true);
                cursor->rotate(false);
            }

            if (condition.compare("RL") == 0)
            {
                cursor->right_node->rotate(false);
                cursor->rotate(true);
            }
        }
    }

    AVLNode<T> *findRoot()
    {
        AVLNode<T> *node = this;
        while (node->parent != NULL)
        {
            node = node->parent;
        }
        return node;
    }

    void insertNode(AVLNode<T> *node)
    {
        if (node->key < this->key)
        {
            if (this->left_node != NULL)
            {
                this->left_node->insertNode(node);
            }
            else
            {
                node->parent = this;
                this->left_node = node;
                findRoot()->__balanceTree(node);
            }
        }

        if (node->key > this->key)
        {
            if (this->right_node != NULL)
            {
                this->right_node->insertNode(node);
            }
            else
            {
                node->parent = this;
                this->right_node = node;
                findRoot()->__balanceTree(node);
            }
        }

        if (node->key == this->key)
        {
            throw std::invalid_argument("same value here");
        }
    }

    AVLNode<T> *findNode(AVLNode<T> *baseNode, T key){

        if (baseNode == NULL)
        {
            throw std::invalid_argument("can not find with this key"+std::to_string(key));
        }
        

        if (baseNode->key == key)
        {
            return baseNode;
        }

        if (baseNode->key > key)
        {
            findNode(baseNode->left_node, key);
        } else {
            findNode(baseNode->right_node, key);
        }
    }

    void deleteNode(T key){
        try
        {
            AVLNode<T> *root = findRoot(this);
            AVLNode<T> *node = findNode(root, key);
            if (node->left_node == NULL && node->right_node == NULL)//leaf node, set to null pointer
            {
                if (node->parent->left_node == node)//left node
                {
                    node->parent->left_node = NULL;
                } else {
                    node->parent->right_node = NULL;
                }
                __balanceTree(node->parent);
                node == NULL;
            }

            if (node->right_node != NULL)
            {
                /* code */
            }
            

            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        

    }
};

template <typename T>
int findDistance(AVLNode<T> *root, AVLNode<T> *node)
{
    AVLNode<T> *n = node;
    int index = 0;
    while (n != root)
    {
        n = n->parent;
        index++;
    }
    return index;
}

template <typename T>
void printTree(AVLNode<T> *root)
{
    std::vector<AVLNode<T> *> vct;
    int hight = root->findHight() + 1;
    std::vector<AVLNode<T> *> *vcts[hight] = {NULL};

    vct.push_back(root);
    while (!vct.empty())
    {
        AVLNode<T> *n = vct.back();
        vct.pop_back();
        // loop action
        int distance = findDistance(root, n);
        if (vcts[distance] == NULL)
        {
            std::vector<AVLNode<T> *> *vector = new std::vector<AVLNode<T> *>();
            vcts[distance] = vector;
        }
        vcts[distance]->push_back(n);
        // std::cout<<std::to_string(findDistance(root, n))<<"-"<<n->key<<std::endl;
        // end loop action
        if (n->right_node != NULL)
        {
            vct.push_back(n->right_node);
        }
        if (n->left_node != NULL)
        {
            vct.push_back(n->left_node);
        }
    }

    int lastLineSize = vcts[hight-1]->size();

    for (size_t i = 0; i < hight; i++)
    {
        int nSize = vcts[i]->size();
        int offset = (lastLineSize - nSize)*5;
        std::cout << std::string( offset, ' ' );
        for (size_t j = 0; j < nSize; j++)
        {
            AVLNode<T> *nNode = vcts[i]->at(j);
            char buffer[50];
            std::string value = std::to_string(nNode->key);
            sprintf(buffer, "  %10s", &value[0]);
            printf(buffer);
        }
        std::cout << std::string( offset, ' ' );
        std::cout << "\n____________" << std::to_string(i) << "____________\n";
        delete vcts[i];
    }
}

int main(int, char **)
{
    auto start = std::chrono::system_clock::now();
    AVLNode<int> node = {1, 0};
    // n2.insertNode(&n1);
    AVLNode<int> *nodes = (AVLNode<int> *)calloc(1000000, sizeof(AVLNode<int>));
    for (int i = 2; i < 1000000; i++)
    {
        nodes[i] = {i};
        node.findRoot()->insertNode(nodes + i);
    }
    //printTree(node.findRoot());
    free(nodes);
    auto end = std::chrono::system_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    // std::cout<<std::to_string(n2.balanceFactor())<<std::endl;
    return 0;
}
