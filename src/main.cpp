#include "manager.h"

#include <print>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  if(argc > 1) 
  {
    std::println("Multiple Arguments provided!");
  }
  Manager server_manager{};

  while(!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }
  return 0;
}
