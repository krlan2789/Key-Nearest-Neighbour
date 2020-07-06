#pragma once

class Sqrt
{
  public:
    // Mencari nilai akar dengan metode pnegurangan
    template<typename T>
    static float subMethod(T squad)
    {
      int i = 0;
      T temp = squad;
      while (temp >= 2)
      {
        temp = temp / 2;
        i++;
      }
      while (true)
      {
        if((i*i) == squad)
        {
          return i;
        }
        else if (squad < (i*i))
        {
          float dec = (float)(squad - ((i-1) * (i-1))) / (i*2);
          dec += (i-1);
          return dec;
        }
        i++;
      }
      return 0;
    }
    // Mencari nilai akar dengan metode nilai rata-rata
    template<typename T>
    static float meanMethod(T squad)
    {
      int i = 0, temp = 0;
      while (temp >= 2)
      {
        temp = temp / 2;
        i++;
      }
      i = temp;
      while (true)
      {
        if((i*i) == squad)
        {
          return i;
        }
        else if (((i*i) < squad) && (((i+1)*(i+1)) > squad))
        {
          float dec = ((squad / i) + i) / 2;
          int j = 0;
          while (!((dec*dec) == squad))
          {
            dec = ((squad / dec) + dec) / 2;
            if (j > 5)
            {
              break;
            }
            j++;
          }
          return dec;
        }
        i++;
      }
      return 0;
    }
};
