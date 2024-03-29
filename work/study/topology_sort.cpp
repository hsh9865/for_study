#include <iostream>
#include <queue>
#include <vector>
#define Max 510
int main()
{
  int n;
  std::cin >>n;
  std::vector<int> degree[Max];
  int from_count[Max] = {0,};
  int time[Max] = {0,};
  int result[Max] = {0,};
  std::queue<int> q;
  for (int i = 0 ; i< n;i++)
    {
      int node;
      std::cin >> time[i];
      while(1)
        {
          std::cin >> node;
          if(node == -1) break;
          degree[node-1].push_back(i);
          from_count[i]++;
        }
    }
  for(int i = 0; i<5;i++)
    {
      for (int j = 0; j <degree[i].size();j++)
        {
          std::cout <<degree[i][j] <<' ';
        }
      std::cout << from_count[i];
      std::cout << '\n';
    }
  for(int i = 0 ; i<n;i++)
  {
    if(from_count[i] == 0) 
    {
      q.push(i);
      result[i] = time[i];
    }
  }

  for(int i = 0 ; i<n;i++)
    {
      if(q.empty())  return -1;
      int cur = q.front();
      q.pop();
      for(int j = 0;j< to_node[cur].size();j++)
        {
          if(to_node[cur][j] == -2) break;
          from_count[to_node[cur][j]]--;
          if(from_count[to_node[cur][j]] == 0) q.push(to_node[cur][j]);
        }
    }
  return 0;
}