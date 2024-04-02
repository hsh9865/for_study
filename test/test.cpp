#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int main(){
  srand(time(NULL));
  int map_list[4][4];
  for(int i = 0; i<4;i++)
    {
      for(int j = 0 ;j<4;j++)
        {
          map_list[i][j]=0;
        }
    }

  int num = rand()%4;
  
  map_list[0][num]=9;
  bool test = std::find(std::begin(map_list[0]), std::end(map_list[0]), 2) != std::end(map_list[0]);
  // std::cout << test << '\n';
  // if(num == 0 || num == 3){
  //   if(num == 0){
  //     int type = rand()%2+1;
  //     map_list[0][num+1] = type;
  //     if(type == 1)
  //     {
  //       type = rand()%2+1;
  //       map_list[0][2]=type;
  //       if(type == 1){
  //         map_list[0][3] = 2;
  //       }
  //     }
  //   }
  //   else if(num == 3){
  //     int type = rand()%2+1;
  //     map_list[0][num-1] = type;
  //     if(type == 1)
  //     {
  //       type = rand()%2+1;
  //       map_list[0][1]=type;
  //       if(type == 1){
  //         map_list[0][0] = 2;
  //       }
  //     }
  //   }
  // }
  // else{
  //   int type = rand()%2;
  //   map_list[0][num-1] = type;
  //   if(type == 0){
  //     if(num+1 ==4) map_list[0][num+1] =2;
  //     else{
  //       type = rand()%2+1;
  //       // std::cout << type << '\n';
  //       map_list[0][num+1] = type;
  //     }
  //   }
  //   else{
  //     type = rand()%2;
  //     // std::cout << type << '\n';
  //     map_list[0][num+1] = type;
  //     if(type == 1){
  //       map_list[0][(num+2)%4] =2;
  //     }
  //   }
  // }
  int count =1;
  int way;
  while(!test)
    {
      if(num -count < 0 || map_list[0][num-count+1]==0){
        way = rand()%2+1;
        map_list[0][num+count] = way;
      }
      else if(num + count >3 || map_list[0][num+count -1] == 0)
      {
        way = rand()%2+1;
        map_list[0][num-count] = way;
      }
      else
      {
        way = rand()%3;
        map_list[0][num-count] = way;
        if(way == 0)
        {
          way = rand()%2+1;
          map_list[0][num+count] = way;
        }
        else if(way ==2)
        {
          break;
        }
        else
        {
          way = rand()%3;
          map_list[0][num+count] = way;
        }
      }
      test = std::find(std::begin(map_list[0]), std::end(map_list[0]), 2) != std::end(map_list[0]);
    }
  for(int i = 0; i<4;i++)
  {
    for(int j = 0 ;j<4;j++)
      {
        std::cout << map_list[i][j] << ' ';
      }
    std::cout << '\n';
  }  
  return 0;
}