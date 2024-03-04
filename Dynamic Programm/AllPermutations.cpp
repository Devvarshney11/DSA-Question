#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void allPermutaions(int idx, string &s, int &n)
{
    if (idx == n - 1)
    {
        cout << s << endl;
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i > 0 && s[i] == s[i - 1])
            continue;
        swap(s[i], s[idx]);
        allPermutaions(idx + 1, s, n);
        swap(s[i], s[idx]);
    }
}
int main()
{
    string s = "aac";
    int n = 3;
    allPermutaions(0, s, n);
    return 0;
}