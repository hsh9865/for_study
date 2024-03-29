#include<iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

void vec_inner(float vec1[3], float vec2[3])
{
  ofstream fout;
  fout.open("output.txt");
  fout<<"scalar" << endl;
  fout<< vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];
  fout.close();
}
void vec_mag(float vec1[3])
{
  float vec_mag = sqrt(vec1[0]*vec1[0]+ vec1[1]*vec1[1] + vec1[2]*vec1[2]);
  ofstream fout;
  fout.open("output.txt");
  fout<<"scalar" << endl;
  fout << vec_mag;
  fout.close();
}
void vec_add(float vec1[3],float vec2[3])
{
  ofstream fout;
  fout.open("output.txt");
  fout<<"vector" << endl;
  float *vec_add = new float[3];
  vec_add[0] = vec1[0] + vec2[0];
  vec_add[1] = vec1[1] + vec2[1];
  vec_add[2] = vec1[2] + vec2[2];
  for(int i = 0 ; i <2 ;i++)
    {
      fout << vec_add[i] << " ";
    }
  fout<< vec_add[2];
  fout.close();
  
}
void vec_cross(float vec1[3], float vec2[3])
{
  ofstream fout;
  fout.open("output.txt");
  fout<<"vector" << endl;
  float *vec_cross = new float[3];
  vec_cross[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
  vec_cross[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
  vec_cross[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
  for(int i = 0 ; i <2 ;i++)
    {
      fout << vec_cross[i] << " ";
    }
  fout<< vec_cross[2];
  fout.close();
}