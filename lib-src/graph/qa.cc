#include <AD/graph/graph.h>
#include <cstdlib>

int main()
{
  GraphObject G;

  for (NodeSet::iterator i = G.nodes(); i; i++)
  {
    const NodeObject * n = *i;
    if (n)
      std::exit(1);
  }
  return 0;
}
