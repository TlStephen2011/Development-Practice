#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Node
{
  public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class Solution
{
  public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void levelOrder(Node *root)
    {
        queue<Node *> myQ;
        if (root)
        {
            myQ.push(root);
            while (!myQ.empty())
            {
                Node *temp = myQ.front();
                myQ.pop();
                cout << temp->data << " ";

                if (temp->left)
                {
                    myQ.push(temp->left);
                }
                if (temp->right)
                {
                    myQ.push(temp->right);
                }
            }
        }
    }
};

int main()
{
    Solution myTree;
    Node *root = NULL;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.levelOrder(root);
    return 0;
}