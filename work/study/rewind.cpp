#include <iostream>
#include <queue>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector <int> degree[n];
  std::queue <int> q;
  int from_count[n] = {0,};
  for(int i =0;i<n;i++)
    {
      int node;
      while(1)
        {
          std::cin >> node;
          if(node == -1) break;
          from_count[i]++;
          degree[node-1].push_back(i);
        }
    }
  for(int i =0;i<n;i++)
    {
      if(from_count[i] == 0)q.push(i);
    }
  while(!q.empty())
    {
      int cur = q.front();
      std::cout << cur << ' ';
      q.pop();
      for(int i =0;i <degree[cur].size();i++)
        {
          from_count[degree[cur][i]]--;
          if(from_count[degree[cur][i]]==0) q.push(degree[cur][i]);
        }
    }
  std::cout<<'\n';
  return 0;
}