#include <iostream>
#include <queue>
#include <vector>

bool visit[1001];
int graph[1001][1001];
std::queue<int> q;
void reset();
void dfs(int start);
void bfs(int start);
int main()
{
  int node;
  int edge;
  int start;

  std::cin >> node >> edge >> start;
  for(int i = 0; i < edge;i++)
    {
      int p1,p2;
      std::cin >> p1 >> p2;
      graph[p1][p2] = 1;
      graph[p2][p1] = 1;
    }
  reset();
  dfs(start);
  reset();
  std::cout << '\n';
  bfs(start);
  return 0;
}
void dfs(int x)
{
  visit[x] = true;
  std::cout << x << ' ';
  for(int i =1;i<1001;i++)
    {
      if(graph[x][i]==1 && visit[i] == false)
        dfs(i);
    }
}
void bfs(int start)
{
  q.push(start);
  visit[start] = true;
  std::cout << start << ' ';
  while(!q.empty())
    {
      int x = q.front();
      q.pop();
      for(int i = 1;i<1001;i++)
        {
          if(graph[x][i]==1 &&visit[i] == false)
          {
            q.push(i);
            visit[i] = true;
            std::cout << i << ' ';
          }
        }
    }
}
void reset()
{
  for(int i = 0; i<1001;i++) visit[i] = false;
}