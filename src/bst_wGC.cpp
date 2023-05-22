#include <iostream>
#include "gc.h"

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            node = new ((Node*)GC_MALLOC(sizeof(Node))) Node(value);
            // node = new Node(value);
        }
        else if (value <= node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else
        {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    bool searchNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        else if (value == node->data)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }


public:
    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    bool search(int value)
    {
        return searchNode(root, value);
    }

    void inorder()
    {
        inorderTraversal(root);
    }
};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(10);
    tree.insert(30);
    tree.insert(4);

    std::cout << "Inorder traversal: " << std::endl;
    tree.inorder();
    std::cout << std::endl;
    int searchValue = 40;
    if (tree.search(searchValue)){
        std::cout << searchValue << " is found in the tree." << std::endl;
    }
    else{
        std::cout << searchValue << " is not found in the tree." << std::endl;
    }
    return 0;
}