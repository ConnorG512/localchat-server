#include "server/server.h"

#include <unistd.h>

Network::Server server_instance{};

int main() {

  Network::Server server_instance{};
  while(true)
  {
    sleep(1);
  }
  return 0;
}
