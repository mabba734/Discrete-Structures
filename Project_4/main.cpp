#include <climits>
#include <iostream>
#include <fstream>
using namespace std;

const int V = 9;
// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j) {
  char str = 65 + j;
  // Base Case : If j is source
  if (parent[j] == -1) {
    cout << str << " ";
    return;
  }

  printPath(parent, parent[j]);

  cout << str << " ";
}

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
  int minimum = INT_MAX, ind;

  for (int k = 0; k < V; k++) {
    if (Tset[k] == false && distance[k] <= minimum) {
      minimum = distance[k];
      ind = k;
    }
  }
  return ind;
}


  /* (4) Please modify the DijkstraAlgo function to have three parameters:
  (1) Two-dimentional array
  (2) Starting Node
  (3) Ending Node
*/
void DijkstraAlgo(int graph[V][V], int src, int endNode) // adjacency matrix
{
  int distance[V]; // array to calculate the minimum distance for each node
  bool Tset[V];    // boolean array to mark visited and unvisited for each node
  int parent[V];   // Parent array to store shortest path tree
                 // Value of parent[v] for a vertex v stores parent vertex of v
                 // in shortest path tree.

  for (int k = 0; k < V; k++) {
    distance[k] = INT_MAX;
    Tset[k] = false;
  }
  parent[src] = -1;  // Parent of root (or source vertex) is -1.
  distance[src] = 0; // Source vertex distance is set 0

  for (int k = 0; k < V; k++) {
    int m = miniDist(distance, Tset);
    Tset[m] = true;
    for (int k = 0; k < V; k++) {
      // updating the distance of neighbouring vertex
      if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX &&
          distance[m] + graph[m][k] < distance[k]) {
        distance[k] = distance[m] + graph[m][k];
        parent[k] = m;
      }
    }
  }
  cout << "EndNode\t\tDistance from source Node\t\t Path" << endl;

  char str=65+endNode;
  cout<<str<<"\t\t\t"<<distance[endNode]<<"\t\t\t\t\t\t\t\t";
  printPath(parent, endNode);
  cout<<endl;

  /*for (int k = 0; k < V; k++) 
  {
    char str = 65 + k;
    // cout<<str<<"\t\t\t"<<distance[k]<<endl;
    cout << str << "\t\t\t" << distance[k] << "\t\t\t\t\t\t\t\t";
    printPath(parent, k);
    cout << endl;
  } */

}
int returnVal(char x)
{

  return (int)x-65;
}


int main() {



  // (1) please modify code here to read this two-dimentional matrix from the data file graph.txt
/*	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
                     {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
                     {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 0, 10, 0, 2, 0, 0},
                     {0, 0, 0, 14, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7},
                     {0, 0, 2, 0, 0, 0, 6, 7, 0}}; */

  ifstream inputFile ("graph.txt");
  if(!inputFile)
  {
    cerr<<"Error opening file."<<endl;
    return 1;
  }
  //const int V=9;
  int graph[V][V]{};
  for(int i{}; i!=V; ++i)
    {
      for(int j{}; j!=V; ++j)
        {
          inputFile>>graph[i][j];
        }
    }

  inputFile.close();
  cout<<"Nodes: A, B, C, D, E, F, G, H, I"<<endl;
  char startingNode, endingNode;
  cout<<"Please enter the starting node: ";
  cin>>startingNode;
  int startNodeInt=returnVal(startingNode);
  cout<<"Please enter the ending node: ";
  cin>>endingNode;
  int endNodeInt=returnVal(endingNode);




  // (2) Please prompt the user to enter the Starting Node from the Keyboard.

// (3) Please prompt the user to enter the Ending Node from the Keyboard.

  /* (4) Please modify the DijkstraAlgo function to have three parameters:
  (1) Two-dimentional array
  (2) Starting Node
  (3) Ending Node
*/
  DijkstraAlgo(graph, startNodeInt, endNodeInt);

  //(5) Please print the shortest distance between the Starting Node and the Ending Node.

  //(6) Please print the shortest path bewteen the Starting Node and the Ending Node.


  return 0;
}
