#include <iostream>
#include <sstream>
#include <map>
#include <iterator>
#include <vector>

#include "dst.h"

const int NUM_OF_BITS = 4;

int main()
{
    // freopen("./input.txt", "r", stdin);
    ::TreeNode *root = loadBinaryTree();
    deleteNode(&root, 4);
    // insertNode(&root, 2);
    // ::TreeNode *search = searchNode(root, 2);
    // std::cout << search->value << " " << std::endl;
    preOrderTraversal(root);
    // std::cout << "ENDL" << std::endl;
}

void persistBinaryTreeHelper(::TreeNode *root);

::TreeNode *loadBinaryTree()
{
    int len;
    std::cin >> len;
    std::string in;
    std::cin.ignore();
    std::getline(std::cin, in);

    std::stringstream ss(in);
    std::string temp;

    int data[len] = {0};
    int nodePositions[len] = {0};

    int i = 0;
    while (ss >> temp)
    {
        if (temp.compare("-") != 0)
        {
            int num = std::stoi(temp);
            data[i] = num;
            nodePositions[i] = 1;
        }
        i++;
    }

    ::TreeNode *nodes[len];
    // reset to null
    for (i = 0; i < len; i++)
    {
        nodes[i] = nullptr;
    }
    for (i = 0; i < len; i++)
    {
        if (nodePositions[i])
        {
            nodes[i] = new ::TreeNode{data[i], nullptr, nullptr};
        }
        else
        {
            nodes[i] = nullptr;
        }
    }

    for (i = 0; i < len; i++)
    {
        if (nodePositions[i] && nodes[i] != nullptr)
        {
            int cmp = 2 * i + 1;
            if (cmp < len)
            {
                nodes[i]->left = nodes[cmp];
            }
            cmp = 2 * i + 2;
            if (cmp < len)
            {
                nodes[i]->right = nodes[cmp];
            }
        }
    }
    return len < 1 ? nullptr : nodes[0];
}

void preOrderTraversal(::TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

/*
 * Operations
 */

void insertNode(::TreeNode **root, int value)
{
    int b = ::NUM_OF_BITS;
    ::TreeNode *temp = *root;
    ::TreeNode *pTemp = nullptr;
    int check = 0;
    while (temp != nullptr && temp->value != value)
    {
        b--;
        pTemp = temp;
        int bitValue = (value >> b);
        check = bitValue & 1;
        if (!check)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == nullptr)
    {
        ::TreeNode *newNode = new ::TreeNode{value, nullptr, nullptr};
        if (root == nullptr)
        {
            *root = newNode;
        }
        else
        {
            if (!check)
            {
                pTemp->left = newNode;
            }
            else
            {
                pTemp->right = newNode;
            }
        }
    }
    else
    {
        std::cout << "The given value was existed" << std::endl;
    }
}

::TreeNode *searchNode(::TreeNode *root, int key)
{
    int b = ::NUM_OF_BITS;
    ::TreeNode *temp = root;
    int check = 0;
    while (temp != nullptr && temp->value != key)
    {
        b--;
        int bitValue = (key >> b);
        check = bitValue & 1;
        if (!check)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return temp;
}

void deleteNode(::TreeNode **root, int key)
{
    int b = ::NUM_OF_BITS;
    ::TreeNode *temp = *root;
    ::TreeNode *pTemp = nullptr;
    int check = 0;
    while (temp != nullptr && temp->value != key)
    {
        b--;
        pTemp = temp;
        check = (key >> b) & 1;
        if (check == 0)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp != nullptr)
    {
        ::TreeNode *target = temp;
        while (temp->left != nullptr || temp->right != nullptr)
        {
            pTemp = temp;
            if (temp->left != nullptr)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        target->value = temp->value;
        if (*root == temp)
        {
            *root = nullptr;
        }
        else
        {
            if (pTemp->left == temp)
            {
                pTemp->left = nullptr;
            }
            else
            {
                pTemp->right = nullptr;
            }
        }
    }
    else
    {
        std::cout << key << " is not found in tree" << std::endl;
    }
}