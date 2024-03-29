#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;
string F(int *arr1, int *arr2, int len) //함수 F를 정의
{
  int count =0; // count를 0으로 정의
  for(int i = 0 ; i< len ; i++)
    {
      if(arr1[i] != arr2[i]) // 원소값이 다르면 count증가
        count++;
    }
  string count_s = to_string(count);
  string length = count_s+"/10000";
  return length;
}
int main()
{

  srand(time(NULL)); //난수생성
  int *arr1 = new int[10000];
  int *arr2 = new int[10000];
  int k_val[] = {1,2,3,4,5,6,7,8,9,10}; // k배열 생성
  for(int i = 0; i<10;i++)
    {
      int a= pow(2,k_val[i]);
      for(int j =0; j <10000;j++)
        {
          arr1[j] = rand() % a; // 랜덤값 할당
          arr2[j] = rand() % a;
        }
      cout<< F(arr1,arr2,10000)<<"\t";
    }
  
  
  return 0;
}
