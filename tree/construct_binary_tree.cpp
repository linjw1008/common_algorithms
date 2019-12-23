//重建二叉树
//给定二叉树的前序遍历和中序遍历结果，重建该二叉树
//二叉树不包含重复数据

#include <iostream>
#include <stdexcept>

using namespace std;

//二叉树
struct BinaryTreeNode
{
    int             value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};


BinaryTreeNode* constructBinaryTree(int *preorderLeft, int *preorderRight, int *inorderLeft, int *inorderRight)
{
    //创建根节点
    //根据前序遍历的特点，第一个值为根节点
    int rootValue = *preorderLeft;
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = rootValue;
    root->pLeft = nullptr;
    root->pRight = nullptr;

    //递归结束条件
    if (preorderLeft == preorderRight)
    {
        if (inorderLeft == inorderRight && *preorderLeft == *inorderLeft)
        {
            return root;
        }
        else
        {
            //logic_error ex("Invalid input.");
            throw std::exception("Invalid input.");
        }
    }

    //从中序遍历中获取根节点的位置
    int *inorderRoot = inorderLeft;
    while (*inorderRoot != rootValue && inorderRoot <= inorderRight)
    {
        inorderRoot++;
    }
    //判断inorderRoot是否正确
    if (inorderRoot == inorderRight && *inorderRoot != rootValue)
    {
        logic_error ex("Invalid input.");
        throw std::exception(ex);
    }

    //递归构建二叉树
    int leftTreeLength = inorderRoot - inorderLeft;
    //构建左子树
    if (leftTreeLength > 0)
    {
        root->pLeft = constructBinaryTree(preorderLeft + 1, preorderLeft + leftTreeLength, inorderLeft, inorderRoot - 1);
    }
    //构建右子树
    if (inorderRight - inorderRoot > 0)
    {
        root->pRight = constructBinaryTree(preorderLeft + leftTreeLength + 1, preorderRight, inorderRoot + 1, inorderRight);
    }

    return root;
}

BinaryTreeNode* ConstructBinaryTree(int *preorder, int *inorder, int len)
{
    if (preorder == nullptr || inorder == nullptr || len < 0)
    {
        return nullptr;
    }

    return constructBinaryTree(preorder, preorder + len - 1, inorder, inorder + len - 1);
}

int main()
{
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* BinaryTree = ConstructBinaryTree(preorder, inorder, 8);
}