#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include "ArgumentManager.h"
using namespace std;

class graph
{
  private:
    int matrix[50][50];
    int size;

  public:
    graph(int n)
    {
      size = n;
      for(int i = 0; i < size; i++)
      {
        for(int j = 0; j < size; j++)
        {
          matrix[i][j] = 0;
        }
      }
    }

    void addEdge(int i, int j)
    {
      matrix[i][j] = 1;
    }

  void print()
  {
    for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }

  bool find(int n)
  {
    stack <int> s;
    bool visited[size];
    for(int i = 0 ; i < size; i++)
    {
      visited[i] = false;
    }
    s.push(n);
    while (!s.empty())
    {
      int v = s.top();
      s.pop();
      if(!visited[v])
      {
        visited[v] = true;
      }
      for(int i = 0; i < size; i++)
      {
        if(matrix[v][i] == 1)
        {
          if(i == n)
          {
            return true;
          }
          else if(!visited[i])
          {
            s.push(i);
          }
        }
      }
    }
    return false;
  }

  bool searchCycle()
  {
    for (int i = 0; i < size; i++)
    {
      if(find(i))
      {
        return true;
      }
    }
  return false;
  }

};

int main(int argc, char *argv[])
{
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
  //ifstream input("input3.txt");
  //ofstream output("output3.txt");

  string line;
  int num, x, y;
  input >> num;
  graph g(num);

  while(getline(input, line))
  {
    if(line.length() > 1)
    {
      stringstream ss(line);
      ss >> x >> y;
      cout << x << " " << y << endl;
      g.addEdge(x, y);
    }
  }
  g.print();
  
  if(g.searchCycle())
  {
    output << "TRUE" << endl;
  }
  else
  {
    output << "FALSE" << endl;
  }
}