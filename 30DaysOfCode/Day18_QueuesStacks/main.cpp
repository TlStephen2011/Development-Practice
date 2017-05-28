#include <iostream>
#include <vector>
using namespace std;

class Solution
{

  public:
    vector<char> stack, queue;

    void pushCharacter(char ch)
    {
        stack.push_back(ch);
    }

    void enqueueCharacter(char ch)
    {
        queue.push_back(ch);
    }

    char popCharacter()
    {
        char ch;
        if (stack.size())
        {
            ch = stack[stack.size() - 1];
            stack.pop_back();
            return ch;
        }
        return ' ';
    }

    char dequeueCharacter()
    {
        char ch;
        if (queue.size())
        {
            ch = queue[0];
            queue.erase(queue.begin());
            return ch;
        }
        return ' ';
    }
};

int main()
{
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++)
    {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (obj.popCharacter() != obj.dequeueCharacter())
        {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome)
    {
        cout << "The word, " << s << ", is a palindrome.";
    }
    else
    {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}