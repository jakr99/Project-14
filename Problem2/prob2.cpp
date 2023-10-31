#include<iostream>
#include<stdexcept>
using namespace std;

class Vector
{
  public:
    // Constructor
    Vector()
    {
      sz = 4;
      max = 0;
      array = new int[sz];
    }

    
    Vector(const Vector& v)
    {
      sz = v.sz;
      max = v.max;
      array = new int[sz]; 
      for (int i = 0; i < max; i++)
      {
        array[i] = v.array[i];
      }
    }


    ~Vector()
    {
      delete[] array;
    }

    
    void push_back(int v)
    {
      
      if (max == sz)
      {
        sz = sz * 2;
        int* new_array = new int[sz];
        for (int i = 0; i < max; i++)
        {
          new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
      }

      array[max] = v;
      max++;
    }

    
    int& operator[](const int idx)
    {
      if (idx < 0 || idx >= max)
      {
        throw invalid_argument("Index out of range");
      }

      return array[idx];
    }

  private:
    int sz;
    int max;
    int* array;
};

int main()
{
  Vector vect; 

  for (int i = 0; i < 10; i++)
  {
    vect.push_back(i);
  }

  Vector copy = vect; 

  for (int i = 0; i < 10; i++)
  {
    cout << copy[i] << endl;
  }

  return 0;
}
