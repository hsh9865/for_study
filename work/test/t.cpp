#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


int calc(std::vector<std::vector<int>> vec, int a , int time[],int value)
{
  if(vec[a].size() == 1) return time[a];
  else
  {
    for(int j = 0 ; j<vec[a].size()-1;j++)
    {
        value += calc(vec,vec[a][j],time,value);
    }
  }
  return value+time[a];
}
int main() {
  int rows;
  std::cin >> rows;
  std::cin.ignore();
  std::vector<std::vector<int>> vec;
  int time[rows];
  for (int i = 0; i < rows; i++) 
  {
    std::string line;
    std::getline(std::cin, line); // 한 줄씩 입력 받음
    std::istringstream iss(line);
    int value;
    int time_value;

    std::vector<int> rowVector; // 각 행을 저장할 벡터 선언

    iss >> time_value;
    time[i] = time_value;
    while (iss >> value) { // 한 줄에서 숫자를 읽어옴
        rowVector.push_back(value-1);
    }
    if (!rowVector
             .empty()) { // 행 벡터가 비어있지 않은 경우에만 2차원 벡터에 추가
      vec.push_back(rowVector);
    }
  }
  for(int i = 0;i<rows/*이부분은 행의 개수*/;i++)
    {
      std::vector<int> total={0};
      for(int j = 0 ; j<vec[i].size()-1;j++)
        {
          int value = 0;
          total.push_back(calc(vec,vec[i][j],time,value));
        }
      int max = *max_element(total.begin(),total.end());
      std::cout << max + time[i] << std::endl;
    }
  return 0;
}