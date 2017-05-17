#include <iostream>
#include <cstddef>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Solution
{
  publi
    Node *insert(Node *h, int d)
    {

        //Need to use the keyWord NEW because we need to keep the memory on the heap rather than the stack
        //because we need to remember the previous values.
        Node *n = new Node(d);
        if (h != NULL)
        {
            Node *current = h;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = n;
        }
        else
        {
            h = n;
        }

        return h;
    }

    void display(Node *head)
    {
        Node *start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{

    Node *head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);

    return 0;
}
