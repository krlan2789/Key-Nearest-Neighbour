#include <iostream>
#include "Sqrt.h"

#pragma once

/*
  Nilai dengan metode ini adalah -1 <= x <= 1
  a = dari 0 ke titik vektor A
  b = dari 0 ke titik vektor B
  ||A|| = panjang dari 0 ke vector A
  (^b) = b / ||B||
  ab = a.(^b)
  ab = a.b / ||B||
  cos = (ab) / ||A||
  cos = a.b / ||B|| / ||A||
  cos = a.b / (||B|| . ||A||)
*/

class CosineSimilarity
{
  public:
    // Mendapatkan panjang vector terkait
    static float getDiffVector(float *vectorA, float *vectorB, int dataLength)
    {
      float ab = CosineSimilarity::multVector(vectorA, vectorB, dataLength);
      float vectorALength = CosineSimilarity::lengthVector(vectorA, dataLength);
      float vectorBLength = CosineSimilarity::lengthVector(vectorB, dataLength);
      return ab / (vectorALength * vectorBLength);
    }
    // Mendapatkan panjang titik tertentu
    static float lengthVector(float *vector, int dataLength)
    {
      float sum = 0.0f;
      for (int i = 0; i < dataLength; i++)
      {
        sum += (vector[i] * vector[i]);
      }
      return Sqrt::meanMethod(sum);
    }
    // Mengkalikan 2 buah vector
    static float multVector(float *vectorA, float *vectorB, int dataLength)
    {
      float sum = 0.0f;
      for (int i = 0; i < dataLength; i++)
      {
        sum += (vectorA[i] * vectorB[i]);
      }
      return sum;
    }
};
