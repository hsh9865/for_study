#include "matrix.h"
#include "vec.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream readFile;
  readFile.open("input.txt");
  if (readFile.is_open()) {
    while (!readFile.eof()) {
      string str;
      getline(readFile, str);
      cout << str << endl;
    }
    readFile.close();
  }
  int rows1, rows2, cols1, cols2 = 10;
  // 2중 포인터를 사용하여 2차원 배열 동적 할당
  float **array1 = new float *[rows1];
  float **array2 = new float *[rows2];
  int value = 1;
  for (int i = 0; i < rows1; ++i) {
    array1[i] = new float[cols1];
    for (int j = 0; j < cols1; j++) {
      array1[i][j] = value++;
    }
  }
  value = 1;
  for (int i = 0; i < rows2; ++i) {
    array2[i] = new float[cols2];
    for (int j = 0; j < cols2; j++) {
      array2[i][j] = value++;
    }
  }

  return 0;
}