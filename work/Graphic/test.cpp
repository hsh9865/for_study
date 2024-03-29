#include "matrix.h"
#include "vec.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream readFile("input.txt");
  if (!readFile.is_open()) {
    cerr << "파일을 열 수 없습니다." << endl;
    return 1; // 파일 열기 실패 시 프로그램 종료
  }

  vector<string> lines; // 각 줄을 저장할 string 벡터
  string line;
  while (getline(readFile, line)) {
    lines.push_back(line); // 파일의 각 줄을 벡터에 추가
  }
  int rows1, rows2, cols1, cols2 = 10;
  // 2중 포인터를 사용하여 2차원 배열 동적 할당
  float **array1 = new float *[rows1];
  float **array2 = new float *[rows2];
  float vec1[3] = {0,0,0};
  float vec2[3] = {0,0,0};
  istringstream ss(lines[0]);
  
  string subs;
  string cals;
  getline(ss, subs, ' ');
  
  vector<float> vec1_vec;
  vector<float> matrix1_size;
  vector<float> matrix2_size;
  vector<float> matrix1;
  vector<float> matrix2;
  if (subs == "vector")
  {
    istringstream ss(lines[1]);
    
    getline(ss, cals, ' ');
    
    if(cals == "mag")
    {
      istringstream ss(lines[2]);
      while(getline(ss,subs,' '))
        {
          vec1_vec.push_back(stof(subs));
        }
      for(int i = 0 ;i<3 ; i++)
      {
        vec1[i] = vec1_vec[i];
      }
      vec_mag(vec1);
    }
    else
    {
      for(int i = 2; i < 4 ;i++)
        {
          istringstream ss(lines[i]);
          while(getline(ss,subs,' '))
            {
              vec1_vec.push_back(stof(subs));
            }
        }
      for(int i = 0 ;i<3 ; i++)
      {
        vec1[i] = vec1_vec[i];
        vec2[i] = vec1_vec[i+3];
      }
      if(cals == "inner")
        vec_inner(vec1,vec2);
      else if(cals == "mag")
        vec_mag(vec1);
      else if(cals == "add")
        vec_add(vec1,vec2);
      else if(cals == "cross")      
        vec_cross(vec1,vec2);
    }
  }
  else if(subs == "matrix")
  {
    istringstream ss(lines[1]);
    getline(ss, cals, ' ');
    if(cals == "trans")
    {
      istringstream ss(lines[2]);
      while(getline(ss,subs,' '))
        {
          matrix1_size.push_back(stof(subs));
        }
      rows1 = matrix1_size[0];
      cols1 = matrix1_size[1];
      for(int i = 3; i < rows1+3; i++)
        {
          istringstream ss(lines[i]);
          while(getline(ss,subs,' '))
            {
                matrix1.push_back(stof(subs));
            }
        }
      for(int i =0;i<rows1;i++)
        {
          array1[i] = new float[cols1];
          for(int j=0;j <cols1;j++)
            {
              array1[i][j] = matrix1[i*cols1+j];
            }
        }
      matrix_trans(array1,rows1,cols1);
    }
    else if(cals == "add")
    {
      istringstream ss(lines[2]);
      while(getline(ss,subs,' '))
        {
          matrix1_size.push_back(stof(subs));
        }
      rows1 = matrix1_size[0];
      cols1 = matrix1_size[1];
      for(int i = 3; i < rows1+3; i++)
        {
          istringstream ss(lines[i]);
          while(getline(ss,subs,' '))
            {
                matrix1.push_back(stof(subs));
            }
        }
      for(int i =0;i<rows1;i++)
        {
          array1[i] = new float[cols1];
          for(int j=0;j <cols1;j++)
            {
              array1[i][j] = matrix1[i*cols1+j];
            }
        }
      istringstream sec(lines[rows1+3]);
      while(getline(sec,subs,' '))
        {
          matrix2_size.push_back(stof(subs));
        }
      rows2 = matrix2_size[0];
      cols2 = matrix2_size[1];
      for(int i = rows1+4; i < rows2+rows1+4; i++)
        {
          istringstream ss(lines[i]);
          while(getline(ss,subs,' '))
            {
                matrix2.push_back(stof(subs));
            }
        }
      for(int i =0;i<rows2;i++)
        {
          array2[i] = new float[cols2];
          for(int j=0;j <cols2;j++)
            {
              array2[i][j] = matrix2[i*cols2+j];
            }
        }
      matrix_add(array1,rows1,cols1,array2,rows2,cols2);
    }
    else if(cals == "mult")
    {
      istringstream ss(lines[2]);
      while(getline(ss,subs,' '))
        {
          matrix1_size.push_back(stof(subs));
        }
      rows1 = matrix1_size[0];
      cols1 = matrix1_size[1];
      for(int i = 3; i < rows1+3; i++)
        {
          istringstream ss(lines[i]);
          while(getline(ss,subs,' '))
            {
                matrix1.push_back(stof(subs));
            }
        }
      for(int i =0;i<rows1;i++)
        {
          array1[i] = new float[cols1];
          for(int j=0;j <cols1;j++)
            {
              array1[i][j] = matrix1[i*cols1+j];
            }
        }
      istringstream sec(lines[rows1+3]);
      while(getline(sec,subs,' '))
        {
          matrix2_size.push_back(stof(subs));
        }
      rows2 = matrix2_size[0];
      cols2 = matrix2_size[1];
      for(int i = rows1+4; i < rows2+rows1+4; i++)
        {
          istringstream ss(lines[i]);
          while(getline(ss,subs,' '))
            {
                matrix2.push_back(stof(subs));
            }
        }
      for(int i =0;i<rows2;i++)
        {
          array2[i] = new float[cols2];
          for(int j=0;j <cols2;j++)
            {
              array2[i][j] = matrix2[i*cols2+j];
            }
        }
      matrix_mult(array1,rows1,cols1,array2,rows2,cols2);
    }
    
  }
  readFile.close(); // 파일 닫기

  return 0;
}