
#include <iostream>


using namespace std;


class TreeNode 
{
private:
    int value;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int newValue) 
    {
        value = newValue;
        left = nullptr;
        right = nullptr;
    } 

    TreeNode()
    {
        value = 0;
        left = nullptr;
        right = nullptr;
    }

    void SetLeft(TreeNode* node) 
    {
        left = node;
    }

    void SetRight(TreeNode* node)
    {
        right = node;
    }

    void SetValue(int iValue)
    {
        value = iValue;
    }

    int GetValue()
    {
        return value;
    }

    TreeNode* GetLeft()
    {
        return left;
    }

    TreeNode* GetRight()
    {
        return right;
    }
};

class BinaryTree 
{
private:
    TreeNode* head;

    void Insert(TreeNode* node, int value)
    {
        if (value < node->GetValue())
            if (node->GetLeft() == nullptr)
                node->SetLeft(new TreeNode(value));
            else
                Insert(node->GetLeft(), value);
        else
            if (node->GetRight() == nullptr)
                node->SetRight(new TreeNode(value));
            else
                Insert(node->GetRight(), value);
    }

    TreeNode* Search(TreeNode* node, int v)
    {
        if (node == nullptr) return nullptr;
        if (v = node->GetValue()) return node;
        return Search(v < node->GetValue() ? node->GetLeft() : node->GetRight(), v);
    }

public:

    BinaryTree(int value) 
    {
        TreeNode* node = new TreeNode(value);
        head = node;
    }

    BinaryTree()
    {
        TreeNode* node = new TreeNode(0);
        head = node;
    }

    void Insert(int value) 
    {
        if (head == nullptr)
        {
            TreeNode* node = new TreeNode(value);
            head = node;
        }
        else
            Insert(head, value);
    }

    TreeNode* Search(int v) 
    {  
        return Search(head, v);
    }
};

void FillTree(BinaryTree* tree, int startIndex, int endIndex, int* myArray)
{
    if (endIndex < startIndex) return;
    int centralIndex = (startIndex + endIndex) / 2;
    tree->Insert(myArray[centralIndex]);
    FillTree(tree, startIndex, centralIndex - 1, myArray);
    FillTree(tree, centralIndex + 1, endIndex, myArray);
}

BinaryTree CreateMinimalBST(int* myArray, int startIndex, int endIndex)
{
    if (myArray == nullptr) return BinaryTree();
    int centralIndex = (startIndex + endIndex) / 2;
    BinaryTree* tree = new BinaryTree(myArray[centralIndex]);
    FillTree(tree, centralIndex + 1, endIndex, myArray);
    FillTree(tree, startIndex, centralIndex - 1, myArray);
    return *tree;
}

int main()
{
    int myArray[] = { 1,2,3,4,5,6,7,8,9 };  // Жиляев Вячеслав РИ-280001
    BinaryTree tree = CreateMinimalBST(myArray, 0, 8);
}
