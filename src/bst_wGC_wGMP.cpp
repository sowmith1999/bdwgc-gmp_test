#include <iostream>
#include "gc.h"
#include "gmp.h"
#include "gmpxx.h"
#include "gmp_func.h"

struct Node
{
    mpz_t data;
    Node *left;
    Node *right;

    Node(mpz_t &value)
    {
        mpz_init_set(data, value);
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    Node *root;

private:
    Node *insertNode(Node *node, mpz_t &value)
    {
        if (node == nullptr)
        {
            node = new ((Node *)GC_MALLOC(sizeof(Node))) Node(value);
        }
        else if (mpz_cmp(value, node->data) <= 0)
        {
            node->left = insertNode(node->left, value);
        }
        else
        {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    Node *findMinNode(Node* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }

    Node *deleteNode(Node *node, mpz_t &value){
        if(node == nullptr){
            return node;
        }
        unsigned long int comp = mpz_cmp(value, node->data);
        if(comp <0 ){
            node->left = deleteNode(node->left, value);
        }
        else if(comp >0){
            node->right = deleteNode(node->right, value);
        }
        else if(comp == 0){
            if(root->left == nullptr){
                Node* temp = root->right;
                return temp;
            }
            else if(root->right == nullptr){
                Node* temp = root->left;
                return temp;
            }
            
            Node* successor = findMinNode(node->right);
            mpz_set(root->data,successor->data);
            root->right = deleteNode(root->right, successor->data);
        }

        return root;
    }

    bool searchNode(Node *node, mpz_t &value)
    {
        if (node == nullptr)
        {
            return false;
        }
        else if (mpz_cmp(value, node->data) == 0)
        {
            return true;
        }
        else if (mpz_cmp(value, node->data) < 0)
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
            std::cout << mpz_get_str(nullptr, 10, node->data) << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(const char *value)
    {
        mpz_t holder;
        mpz_init(holder);
        mpz_set_str(holder, value, 10);
        std::cout << mpz_get_str(nullptr, 10, holder) << std::endl;
        root = insertNode(root, holder);
    }

    void remove(const char *value){
        mpz_t holder;
        mpz_init(holder);
        mpz_set_str(holder, value, 10);
        root = deleteNode(root, holder);
    }

    bool search(mpz_t &value)
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
    mp_set_memory_functions(&allocate_function,
                            &reallocate_function,
                            &deallocate_function);
    BST tree;

    tree.insert("10");
    tree.insert("20");
    tree.insert("30");
    tree.insert("40");

    mpz_t value;
    mpz_init(value);
    mpz_set_ui(value, 20);
    tree.remove("20");
    
    std::cout << "Inorder traversal" << std::endl;
    tree.inorder();
    
    // if (tree.search(searchValue)){
    //     std::cout << searchValue << " is found in the tree." << std::endl;
    // }
    // else{
    //     std::cout << searchValue << " is not found in the tree." << std::endl;
    // }
    return 0;
}