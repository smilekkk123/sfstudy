#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void removeSpace(string &s)
{
    int slow = 0, fast = 0;
    while (fast < s.length())
    {
        if (s[fast] != ' ')
        { // 一旦遇到不为空格的，则处理
            s[slow++] = s[fast];
            if (s[fast + 1] == ' ' && fast != s.length() - 1) // 加后面这个判断是因为有可能是最后一个单词了
            { 
                s[slow++] = ' ';
            }
        }
        if (fast == s.length() - 1 && s[fast] == ' ')
        {
            slow--; // 因为slow这里只有一个空格
        }
        fast++;
    }
    s.resize(slow);
}

string reverseWords(string s)
{
    removeSpace(s); // 去掉多余空格
    reverse(s.begin(), s.end());
    int i = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (s[j] == ' ')
        {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        if (j == s.length() - 1)
        { // 最后一个单词是没有空格的
            reverse(s.begin() + i, s.end());
        }
    }

    return s;
}

int main()
{
    cout << reverseWords("the sky is blue") << endl;

    return 0;
}