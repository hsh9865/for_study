#include <iostream>

const int Max = 101;
int graph[Max][Max];
int n,m;
void bfs(int x,int y)
{
  
}
int main()
{
  std::cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++)
    {
        graph[i][j] = str[j] - '0';
    }
  }
}