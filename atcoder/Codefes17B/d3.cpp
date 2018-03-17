#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[1000000];
int main()
{
  int num;
  scanf("%d", &num);
  string s;
  cin >> s;
  s = "0" + s + "0";
  for (int i = 1; i < s.size() - 1; i++)
  {
    dp[i + 1] = max(dp[i + 1], dp[i]);
    if (s[i - 1] == '1'&&s[i] == '0'&&s[i + 1] == '1')
    {
      int a = i - 1, b = i + 1;
      for (;;)
      {
        if (s[a] == '0')break;
        dp[i + 1] = max(dp[i + 1], dp[a - 1] + (i - a));
        a--;
      }
      for (;;)
      {
        if (s[b] == '0')break;
        dp[b] = max(dp[b], dp[i - 2] + (b - i));
        b++;
      }
    }
  }
  printf("%d\n", dp[s.size() - 1]);
}
