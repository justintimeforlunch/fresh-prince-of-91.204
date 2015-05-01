// Copyright [2015] Justin Nguyen

#include <iostream>
#include <string>
#include <algorithm>
#include "ED.hpp"

ED::ED(std::string s1, std::string s2) {
  N = s1.size();
  M = s2.size();
  string1 = s1;
  string2 = s2;
  opt = new int*[N + 1];
  for (int i = 0; i <= N; i++)
    opt[i] = new int[M + 1];
  for (int i = 0; i <= N; i++)
    opt[i][M] = ((N - i) * 2);
  for (int j = 0; j <= M; j++)
    opt[N][j] = ((M - j) * 2);
}

ED::~ED() {
  for (int i = 0; i < N ; ++i)
    delete[] opt[i];
  delete opt;
}

int ED:: penalty(char a, char b) {
  if (a == b)
    return 0;
  else
    return 1;
}

int ED::min(int a, int b, int c) {
  if (a < b && a < c)
    return a;
  if (b < c)
    return b;
  return c;
}

int ED::OptDistance() {
  for (int i = M - 1; i >= 0; i--) {
    for (int j = N - 1; j >= 0; j--) {
      if (!(penalty(string1[j], string2[i]))) {
        opt[j][i] = opt[j + 1][i + 1];
      } else {
        opt[j][i] = min(opt[j][i + 1] + 2,
                        opt[j + 1][i] + 2, opt[j + 1][i + 1] + 1);
      }
    }
  }
  return opt[0][0];
}

std::string ED::Alignment() {
  std::string result;
  int i = 0;
  int j = 0;
  while (i < N || j < M) {
    if (!(penalty(string1[i], string2[j]))) {
      result = result + string1[i] + string2[j] + std::to_string(0);
      i += 1;
      j += 1;
    } else if (opt[i][j] == (opt[i + 1][j] + 2)) {
      result = result + string1[i] + "-" +  std::to_string(2);
      i += 1;
    } else if (opt[i][j] == (opt[i][j + 1] + 2)) {
      result = result + "-" + string2[j] + std::to_string(2);
      j += 1;
    } else {
      result = result + string1[i] + string2[j] + std::to_string(1);
      i += 1;
      j += 1;
    }
  }
  return result;
}

int** ED::getOpt() {
  return opt;
}

int ED::getN() {
  return N;
}

int ED::getM() {
  return M;
}
