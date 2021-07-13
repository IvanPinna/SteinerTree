#include <iostream>
#include <math.h>

#define INF 2147483647

using namespace std;

void permutation(bool* array, int tam)
{
  bool bandera = false;
  for(int i = tam-1; i >= 0 && !bandera; --i)
  {
    if(array[i])
      array[i] = false;
    else
    {
      array[i] = true;
      bandera = true;
    }
  }
}

int main(){
  int tam;
  cout << "n?" << endl;
  cin >> tam;
  //int tam = 5;
  bool *array = new bool[tam];
  for(int i = 0; i < tam; ++i)
    array[i] = false;
    
  array[tam-1] = true;
  int contador = 0;
  int limite = pow(2,tam) - 1;
  bool bandera;
  while(contador != limite)
  {
    permutation(array, tam-1);
    
    //Array visualization
    for(int i = 0; i < tam; ++i)
      cout << array[i];
    cout << " " << endl;

    ++contador;
  }

  delete[] array;
}

