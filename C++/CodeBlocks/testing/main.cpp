#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
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

    int getHeight(Node *root)
    {
        int currentLength = 0, maxLength = 0;
        Node *current = root;
        vector<Node> makeChoicePos;
        vector<int> lengthAtChoice;
        bool makeChoice = current->left && current->right;
        bool deadEnd = !current->left && !current->right;

        do
        {
            if (!makeChoice && deadEnd)
            {
                return maxLength;
            }
            else if (makeChoice)
            {
                Node temp = *current;
                makeChoicePos.push_back(temp);
                lengthAtChoice.push_back(currentLength);
                current = current->left;
                currentLength++;
            }
            else if (!makeChoice && !deadEnd)
            {
                if (current->left)
                {
                    current = current->left;
                    currentLength++;
                }
                else
                {
                    current = current->right;
                    currentLength++;
                }
            }
            else
            {
                current = &makeChoicePos[makeChoicePos.size() - 1];
                makeChoicePos.pop_back();
                currentLength = lengthAtChoice[lengthAtChoice.size() - 1];
                lengthAtChoice.pop_back();
                current = current->right;
                currentLength++;
            }

            if (currentLength > maxLength)
            {
                maxLength = currentLength;
            }

            bool makeChoice = current->left && current->right;
            bool deadEnd = !current->left && !current->right;

        } while ((makeChoicePos.size() > 0) || !deadEnd);

        return maxLength;
    }
};

int main()
{
    Solution myTree;
    Node *root = NULL;
    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
