//二叉树的下一个节点
//给定二叉树和其中一个节点，找出中序遍历序列的下一个节点

#include <iostream>
#include <stdexcept>

using namespace std;

//二叉树
struct BinaryTreeNode
{
    char            value;
    BinaryTreeNode* pLeft = nullptr;
    BinaryTreeNode* pRight = nullptr;
    BinaryTreeNode* pParent = nullptr;
};

BinaryTreeNode* GetNextNode(BinaryTreeNode* pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode* pNext = nullptr;

    if (pNode->pRight != nullptr)
    {
        pNext = pNode->pRight;
        while(pNext->pLeft != nullptr)
        {
            pNext = pNext->pLeft;
        }
    }
    else if (pNode->pParent != nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->pParent;
        while (pParent != nullptr && pParent->pRight == pCurrent)
        {
            pCurrent = pParent;
            pParent = pParent->pParent;
        }
        pNext = pParent;
    }

    return pNext;
}

int main()
{
    BinaryTreeNode* aPtr;
    aPtr = new BinaryTreeNode;
    aPtr->value = 'a';
    BinaryTreeNode* bPtr;
    bPtr = new BinaryTreeNode;
    bPtr->value = 'b';
    BinaryTreeNode* cPtr;
    cPtr = new BinaryTreeNode;
    cPtr->value = 'c';
    BinaryTreeNode* dPtr;
    dPtr = new BinaryTreeNode;
    dPtr->value = 'd';
    BinaryTreeNode* ePtr;
    ePtr = new BinaryTreeNode;
    ePtr->value = 'e';
    BinaryTreeNode* fPtr;
    fPtr = new BinaryTreeNode;
    fPtr->value = 'f';
    BinaryTreeNode* gPtr;
    gPtr = new BinaryTreeNode;
    gPtr->value = 'g';
    BinaryTreeNode* hPtr;
    hPtr = new BinaryTreeNode;
    hPtr->value = 'h';
    BinaryTreeNode* iPtr;
    iPtr = new BinaryTreeNode;
    iPtr->value = 'i';
    aPtr->pLeft = bPtr;
    aPtr->pRight = cPtr;
    bPtr->pLeft = dPtr;
    bPtr->pRight = ePtr;
    cPtr->pLeft = fPtr;
    cPtr->pRight = gPtr;
    ePtr->pLeft = hPtr;
    ePtr->pRight = iPtr;
    
    hPtr->pParent = ePtr;
    iPtr->pParent = ePtr;
    dPtr->pParent = bPtr;
    ePtr->pParent = bPtr;
    fPtr->pParent = cPtr;
    gPtr->pParent = cPtr;
    bPtr->pParent = aPtr;
    cPtr->pParent = aPtr;

    BinaryTreeNode* ptr = nullptr;
    ptr = GetNextNode(aPtr);
    cout << "The next node of " << aPtr->value << " is " << ptr->value << endl;
    ptr = GetNextNode(gPtr);
    cout << "The next node of " << gPtr->value << " is " << (ptr == nullptr ? '/' : ptr->value) << endl;
    ptr = GetNextNode(hPtr);
    cout << "The next node of " << hPtr->value << " is " << ptr->value << endl;

    return 0;
}