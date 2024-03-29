#include <iostream>
#include <queue>
#include <vector>
#define Max 510
int Bigger(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}
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
      while(1) //만약에 입력이 x from식으로 입력한다면
        {
          std::cin >> node;
          if(node == -1) break;
          degree[node-1].push_back(i);
          from_count[i]++;
        }
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
      for(int j = 0;j< degree[cur].size();j++)
        {
          int next = degree[cur][j];
          if(next == -2) break;
          from_count[next]--;
          result[next] = Bigger(result[next],result[cur]+time[next]);
          if(from_count[next] == 0) q.push(next);
        }
    }
  for (int i = 0;i<n;i++) std::cout<<result[i] <<'\n';
  return 0;
}