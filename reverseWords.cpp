#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <stdbool.h>

string reverseWords(string str)
{
    int i = 0;
    string result = "";
    stack<char> st;
    while (str[i] != '\0')
    {
        int j;
        for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
        {
            st.push(str[j]);
        }
        while (!st.empty())
        {
            result = result + st.top();
            st.pop();
        }
        if (str[j] == ' ')
        {
            i = j + 1;
            result += " ";
        }
        else if (str[j] == '\0')
            i = j;
    }

    return result;
}

int main(){

    string str = "Suraj is a boy";
    string result = reverseWords(str);
    cout<< result;

return 0;
}