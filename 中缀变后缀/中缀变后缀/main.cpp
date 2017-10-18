

#include <iostream>
#include <stack>

using namespace std;
int compare(char op1, char op2)
{
    if (op2 == '=')
    {
        return 1;
    }
    if (op1 == '(')
    {
        return 1;
    }
    if (op1 == '+' || op1 == '-')
    {
        if (op2 == '*' || op2 == '/')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if (op1 == '*' || op1 == '/')
    {
        if (op2 == '+' || op2 == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    stack <char>s2;
    s2.push('=');
    string s;
    cin >> s;
    for (int j,i = 0; i<s.length(); i++)
    {
        if (s[i]>= 48 && s[i]<= 57 )
        {
            j = i + 1;
            while (s[j] >= 48 && s[j] <= 57)
            {
                j++;
            }
            cout << s.substr(i, (j - i));
        }
        else
        {
            if (s[i] != ')')
            {
                if (1 == compare(s[i], s2.top()))
                {
                    s2.push(s[i]);
                    continue;
                }
                if (compare(s[i], s2.top()) == 0)
                {
                    while(compare(s[i], s2.top()) == 0)
                    {
                        cout << s2.top();
                        s2.pop();
                    }
                }
            }
            
            if (s[i] == ')')
            {
                while (s2.top() != '(')
                {
                    cout << s2.top();
                    s2.pop();
                }
                s2.pop();
            }
            
        }
    }
    while (s2.top() != '=') {
        cout << s2.top();
        s2.pop();
    }
    cout << endl;
    
    return 0;
}
