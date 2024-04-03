#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
const int max= 5;
/*
코드 목적 : 한배열의 방을 받고 랜덤하게 배치를하고 길이 어떻게 뚫려있을지 랜덤하게 할당한다
0 : 고립되어있는 방
1 : 옆으로만 뚫려있는방
2 : 옆과 아래로만 뚫려있는 방
3 : 옆과 위로만 뚫려있는 방
  */
int main(){
  srand(time(NULL));
  int map_list[max][max];
  for(int i = 0; i<max;i++)
    {
      for(int j = 0 ; j < max;j++)
        {
          map_list[i][j]=0;
        }
    }

  int num = rand()%max;
  // int num = 1;  
  
  int count =1;
  int way;
  int next_num;
  for (int i = 0;i<max;i++)
    {
      map_list[i][num]=9;
      while(1)
      {
        bool test = std::find(std::begin(map_list[i]), std::end(map_list[i]), 2) != std::end(map_list[i]);
        if(num-count <0 && num+count>max-1){
          if(!test)
          {
            std::cout << "find" << '\n';
            if(map_list[i][0] == 1)
            {
              next_num = 0;
              map_list[i][0] = 2;
            }
            else 
            {
              next_num = max-1;
              map_list[i][max-1] = 2;
            }
          }
          break;
        }

        if(num == 0 || num == max-1)
        {
          if(count == 1){
            way = rand()%2;
            way +=1;
          }
          else 
          {
            if(!test)
            {
              if(count == max-1) way =2;
              else{
                way = rand()%2;
                way +=1;
              }
            }
            else way = rand()%2;
          }
          if(num == 0 && map_list[i][num+count-1]!=0)
          {
            if(way == 2) next_num = count;
            map_list[i][count] = way;
          }
          else if(num == max-1 && map_list[i][num-count+1] != 0)
          {
            if(way == 2) next_num = max-count-1;
            map_list[i][max-count-1] =way;
          }
        }
        else{
          if(num -count > -1)
          {
            if(test)
              {
                way = rand()%2;
              }
              else
              {
                way = rand()%3;
                
              }
              if(map_list[i][num-count+1]!=0)
              {
                if(way == 2)next_num = num-count;
                map_list[i][num-count] = way;
              }
          }
          test = std::find(std::begin(map_list), std::end(map_list), 2) != std::end(map_list);

          if(num + count < max)
          {
            if(test)
            {
              way = rand()%2;
            }
            else
            {
              way = rand()%2;
              way+=1;
            }
            if(map_list[i][num+count-1]!=0)
            {
              if(way == 2)next_num = num+count;
              map_list[i][num+count] = way;
            }
          }
        }

        count++;
      }
      num = next_num;
    }
  
  std::cout << '\n';
  for(int i = 0; i<max;i++)
  {
    std::cout << map_list[i] << ' ';
    
  } 
  std::cout << '\n';
  return 0;
}