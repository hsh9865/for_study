#include<iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

void matrix_add(float **matrix1, int row1,int col1, float **matrix2,int row2,int col2)
{
  ofstream fout;
  fout.open("output.txt");
  fout<<"matrix" << endl;
  if(row1 != row2 || col1 != col2)
  {
    fout << "NotMached" << endl;
    return;
  }
  float **resultArray = new float*[row1];
  for(int i = 0;i<row1;i++)
    {
      resultArray[i] = new float[col1];
      for(int j = 0;j<col1 ; j++)
        {
          resultArray[i][j] = matrix1[i][j]+ matrix2[i][j];
          fout << resultArray[i][j] << "\t";
        }
      fout << endl;
    }
  fout.close();
}
void matrix_mult(float **matrix1, int row1,int col1, float **matrix2,int row2,int col2)
{
  ofstream fout;
  fout.open("output.txt");
  fout<<"matrix" << endl;
  if(col1 != row2)
  {
    fout << "NotMached" << endl;
    return;
  }
  fout<< row1 << " " << col2 <<endl;
  float **resultArray = new float*[row1];
  // for (int i = 0 ; i < row1 ; i++)
  //   {
      
  //   }
  for (int i = 0 ; i <row1 ; i++)
    {
      resultArray[i] = new float[col2];
      for (int j = 0 ; j < col2 ; j++)
        {
          for(int k =0 ; k < col1 ; k++)
            {
              resultArray[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
  for(int i =0 ; i < row1 ; i++)
    {
      for(int j =0 ; j < col2 ; j++)
        {
          fout << resultArray[i][j] << "\t";
        }
      fout << endl;
    }
  fout.close();
}
void matrix_trans(float **matrix1, int row1,int col1)
{
  ofstream fout;
  fout.open("output.txt");
  fout<<"matrix" << endl;
  float **resultArray = new float*[col1];
  fout << row1 <<" "<< col1 << endl;
  for(int i = 0 ; i <col1; i++)
    {
      resultArray[i] = new float[row1];
      for(int j=0; j< row1; j++)
        {
          resultArray[i][j] = matrix1[j][i];
          fout << resultArray[i][j] << "\t";
        }
      fout << endl;
    }
  fout.close();
}