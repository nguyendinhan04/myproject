#include <bits/stdc++.h>
#include <math.h>
#include <string.h>

using namespace std;

int n;
char s[5];

int trans_()
{
    int N = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '1')
        {
            N = N + (int)pow(2, strlen(s) - 1 - i);
        }
    }
    return N;
}

int main()
{
    int cot = 0;
    scanf("%d", &n);
    fflush(stdin);
    scanf("%s", s);

    int m = trans_();
    int i;
    for (i = 0; i <= (int)pow(2, n) - 1; i++)
    {
        if ((i & m) != m)
        {
            cot++;
        }
    }
    printf("%d", cot);
}