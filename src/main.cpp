#include "manager.h"

int main() {
  Manager server_manager{};

  while(!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }
  return 0;
}
