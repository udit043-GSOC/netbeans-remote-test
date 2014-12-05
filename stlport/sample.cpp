#include <map>

#include <string.h>

int main(int argc, char* argv[])
{
  std::map<int, int> map;

  map[1] = 1;

  std::map<int, int>::iterator it;

  it = map.begin();

  printf("%d\n", it->first);

  it->second = 2;

  map.clear();

  return 0;
}
