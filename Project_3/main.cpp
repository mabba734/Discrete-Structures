//Marim Abbas
//10/18/2023
//Project: Gaussian Elimination Implementation in C++

#include <iostream>
using namespace std;

int main() {

	const int NUM_ROW = 3;
	const int NUM_COL = 4;
	double aug_matrix[NUM_ROW][NUM_COL] = {{2,-3,1,-22},
	                                       {7,9,-3,14},
	                                       {6,7,2,91}};

//gaussian elimination
  for(int i=0; i<NUM_ROW;i++)
  {
    double divisor=aug_matrix[i][i];
     //make diagnol element be 1
    for(int j=0; j<NUM_COL; j++)
      {
        aug_matrix[i][j]/=divisor;
      }
    //make all numbers around it be 0
    for(int j=0; j<NUM_ROW; j++)
      {
        if(j!=i)
        {
          double multiplier=-aug_matrix[j][i]; //jth row-horizontal

          //update each element using mulitper
          for(int k=0;k<NUM_COL;k++)
            {
              aug_matrix[j][k]+=multiplier*aug_matrix[i][k];
            }
        }
      }
  }


	//nested for loop to display the augment matrix
	for(int i = 0; i < NUM_ROW; i++)
	{
		for(int j = 0; j < NUM_COL; j++)
				cout << aug_matrix[i][j] << " ";
		cout << endl;
	}					

	

	return 0;
}
