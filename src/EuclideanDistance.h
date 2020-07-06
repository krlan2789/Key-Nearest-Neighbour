#include <iostream>
#include "Sqrt.h"

#pragma once

class EuclideanDistance
{
  public:
    // Method mendapatkan jarak diagonal dara 2 titik
    static float getDiagonalDistance(float data1[], float data2[])
    {
      float sum = 0.0f;
      float a = data1[0] - data2[0];
      float b = data1[1] - data2[1];
      sum = (a*a) + (b*b);
      return Sqrt::meanMethod(sum);
    }
    // Mengambil nilai absolute selisih dari 2 sumbu
    static float diffValue(float value1, float value2)
    {
      float highAbs = EuclideanDistance::absValue((value1 - value2));
      return highAbs;
    }
    // Merubah nilai menjadi absolute
    static float absValue(float value)
    {
      if (value < 0)
      {
        value *= (-1);
      }
      return value;
    }
};

