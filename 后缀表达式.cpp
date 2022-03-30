#include <stack>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    char s2[100];
    double v1, v2, v3, v4 = 1;
    cin >> s2;
    stack<double> s;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] > '0' && s2[i] < '9')
        {
            v3 += s[i] * v4++;
        }
        else if (s[i] == ' ')
        {
            v4 = 1;
            v3 = 0;
        }
        else
        {
            v1 = s.top();
            s.pop();
            v2 = s.top();
            s.pop();
            if (s2[i] == '+')
            {
                s.push(v2 + v1);
            }
            else if (s2[i] == '-')
            {
                s.push(v2 - v1);
            }
            else if (s2[i] == '*')
            {
                s.push(v2 * v1);
            }
            else if (s2[i] == '/')
            {
                s.push(v2 / v1);
            }
        }
    }
    cout << s.top();
}