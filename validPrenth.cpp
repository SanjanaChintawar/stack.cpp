#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if there is a opening bracket then push it into the stack
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        // if closing bracket is there then check the top and pop
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{'))
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    string ex = "{[({})]}}";
    bool is_valid;

    is_valid = isValid(ex);

    if (is_valid)
    {
        cout << "A balanced expression.";
    }
    else
    {
        cout << "Not a balanced expression.";
    }
}