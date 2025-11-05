#include "manager.h"
#include <iostream>

int main(int argc, const char* argv[]) {
  Manager server_manager{};

  std::span<const char*> args(argv, argv+argc);
  for(auto string : args)
  {
    std::cout << string << "\n";
  }

  while(!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }
  return 0;
}
