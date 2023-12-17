#include <iostream>
#include <stack>
#include <vector>

int main() 
{
  std::stack<int> usadas;
  std::vector<int> lista;
  lista={1,5,10,15,20,25};
  int tam = lista.size();
  int cambio = 24;
  
  std::cout << "Para dar cambio de $" << cambio << " se necesitan:\n";

  for(int i = tam-1; i >= 0; i--)
  {
    while(cambio >= lista[i])
    {
      cambio = cambio - lista[i];
      usadas.push(lista[i]);
    }
  }
  while (!usadas.empty())
  {
    std::cout << "\nMoneda de: $" << usadas.top();
    usadas.pop();
  }
}