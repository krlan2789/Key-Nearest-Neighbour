#include <string>

#pragma once

class Data
{
  private:
    // Menyimpan jumlah baris dan kolom
    int row = 0, col = 0;
    // Menyimpan nama kategori
    std::string category;
    // Menyimpan kumpulan data
    float* point[];

    // Mengatur parameter
    void setParamLength(int col)
    {
      if (col < 0)
      {
        col = 0;
      }
      this->row = row;
      this->col = col;
      *this->point = new float[this->row];
    }
    // Mengatur kategori
    void setCat(std::string category)
    {
      this->category = category.data();
    }

  public:
    // Constructor
    Data()
    {
    }
    
    Data(int col, std::string category)
    {
      this->setParamLength(col);
      this->setCat(category);
    }
    // Mengambil kategori
    char* getCat()
    {
      return this->category.data();
    }
    // Mengambil ukuran data
    int getLength(bool row = false)
    {
      if (!row)
      {
        if (this->row > 1)
        {
          return this->row - 1;
        }
        return this->row;
      }
      else
      {
        return this->col;
      }
    }
    // Menambahkan data
    void addData(float *datum)
    {      
      this->row += 1;
      if (this->row == 2)
      {
        this->row += 1;
      }
      this->point[this->row] = new float[this->col];
      for (int j = 0; j < this->col; j++)
      {
        this->point[this->row][j] = datum[j];
      }
    }
    // Mengambil data
    float* getPoint(int row)
    {
      return this->point[row];
    }
    // Mengambil semua data
    float** getPoints()
    {
      float** data = new float*[this->row-1];
      int j = 0;
      for (int i = 0; i < this->row; i++)
      {
        j = i;
        if (i > 1)
        {
          j--;
        }
        data[j] = new float[this->col];
        data[j] = this->point[i+1];
      }
      return data;
    }
};
