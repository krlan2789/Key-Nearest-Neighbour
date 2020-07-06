#include <iostream>
#include <string.h>
#include "Data.h"
#include "EuclideanDistance.h"
#include "CosineSimilarity.h"

#pragma once

class KeyNearestNeighbour
{
  private:
    // Jumlah kelompok data dan jumlah ey
    int dataLength, key;
  
  public:
    Data* category[];
    // Constructor
    KeyNearestNeighbour()
    {
      this->dataLength = 0;
      this->key = 1;
    }
    // Mengatur jumlah key
    void setKey(int key)
    {
      if (key > 1 && key < this->category[this->dataLength-1]->getLength())
      {
        this->key = key;
      }
    }
    // Menambahkan kelompok data
    void addCategory(Data* data)
    {
      this->category[this->dataLength] = new Data(data->getLength(true), data->getCat());
      this->dataLength++;
      std::cout << "Menambah kategori : " << this->category[this->dataLength-1]->getCat() << std::endl; 
      float* point[data->getLength()];
      for (int i = 0; i < data->getLength(); i++)
      {
        point[i] = data->getPoint(i);
        // std::cout << this->dataLength << "\ti-" << i << std::endl;
        std::cout << "Menambah point : ";
        std::cout << point[i][0] << " - " << std::endl;
        // this->category[this->dataLength-1]->addData(data->getPoint(i));
        // delete point[i];
      }
    }
};