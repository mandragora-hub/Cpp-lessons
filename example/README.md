# Code interesting example

## geopts.cpp

<https://riptutorial.com/c/example/30858/using-gnu-getopt-tools?source=post_page-----36913284460f-------------------------------->

## split

```c
#include <iterator>
#include <iostream>

int main(int argc, char* argv[]) {
  std::copy(argv, argv + argc, std::ostream_iterator<char *>(std::cout, "\n"));

  return 0;
}

```