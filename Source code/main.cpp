#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "Prim.hpp"

using namespace std;

/* 
   Returns the next combinations of a binary string. The binary 
   string is implemented as a vector of booleans named 'array'.
*/
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

void showBool(bool* array, int tam)
{
  for(int i = 0; i < tam; ++i)
    cout << array[i] << " ";
  cout << " " << endl;
}

int main(int argc, char *argv[]){
  Prim objeto;
  int rows, cols;
  int allnodes = 25; //Numbers of nodes
  int opcionales = atoi(argv[1]);   // 0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22   23  24
  int matrix[allnodes][allnodes] = {{  0, 1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF},
				    /*1*/ {  1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   5, INF, INF, INF, INF},
				    /*2*/ {INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   6, INF, INF, INF, INF},
				    /*3*/ {INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   7,   6, INF, INF, INF},
				    /*4*/ {INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   5, INF, INF, INF},
				    /*5*/ {  1, INF, INF, INF, INF,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, 
				    /*6*/ {INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
				    /*7*/ {INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
				    /*8*/ {INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
				    /*9*/ {INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
				    /*10*/{INF, INF, INF, INF, INF,   1, INF, INF, INF, INF,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF, INF},
				    /*11*/{INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF, INF},
				    /*12*/{INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF, INF},
				    /*13*/{INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF},
				    /*14*/{INF, INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF,   1, INF, INF, INF, INF, INF},
				    /*15*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF, INF,   0,   1, INF, INF, INF, INF, INF,   4, INF,   4},
				    /*16*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF, INF,   0,   1, INF, INF, INF, INF, INF, INF,   5},
				    /*17*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF, INF, INF,   6},
				    /*18*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0,   1, INF, INF, INF, INF,   7},
				    /*19*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF,   1,   0, INF, INF, INF,   5,   6},
				    /*20*/{  4,   5,   6,   7, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   0,  30,  32, INF, INF},
				    /*21*/{INF, INF, INF,   6,   5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,  30,   0, INF,  44, INF},
				    /*22*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF,  32, INF,   0, INF,  70},
				    /*23*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,  44, INF,   0,  55},
				    /*24*/{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   4,   5,   6,   7,   6, INF, INF,  70,  55,   0}};
				    

  //Bool array to determine which allnodes are selected
  bool *selected = new bool[allnodes];
  int activenodes = 0;
  for(int i = 20; i < allnodes; ++i)
  {  if(i < 20)
      selected[i] = false;
    else
      selected[i] = true;
  }

  
  //Create submatrix. If we take the maximum possible space we don't need overwrite.
  int** subMatrix = new int*[allnodes];
  for(int i = 0; i < allnodes; ++i)
    subMatrix[i] = new int[allnodes];

  int limite = pow(2,opcionales)-1;
  int contador = 0;
  int costeMin = INF;
  double start, stop;
  start = clock();
  while(contador <= limite) //The first iteration is without opcional vertex.
  {
    //cout << "Permutacion " << contador << ": ";
    //showBool(selected, allnodes);
    //Insert values into submatrix for Prim
    int s_x = 0, s_y = 0;
    for(int i = 0; i < allnodes; ++i)
    {
      s_y = 0;
      for(int j = 0; j < allnodes; ++j)
      {
	if(selected[i] and selected[j])
	{
	  subMatrix[s_x][s_y] = matrix[i][j];
	  ++s_y;
	}
      }
      if(selected[i])
	++s_x;
    }

    activenodes = 0;
    for(int i = 0; i < allnodes; ++i)
      if(selected[i])
	++activenodes;
    
    // allnodes is used to know matrix length.
    Prim::solution S = objeto.algPrim(subMatrix, activenodes);
    if(S.coste_total < costeMin)
      costeMin = S.coste_total;
    
    //Generate next permutation
    permutation(selected, 20); //To take first 20 positions.
    

    ++contador;
  }
  stop = (clock() - start)/CLOCKS_PER_SEC;
  cout << "Time " << stop << endl;
  cout << "Coste minimo: " << costeMin << endl;
  
  //deleting dinamic subMatrix
  for(int i = 0; i < allnodes;++i)
    delete[] subMatrix[i];
  delete[] subMatrix, selected;
}
