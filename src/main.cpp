#include "server/server.h"

#include <unistd.h>

int main() {

  Networking::Server server_instance{};
  while(true)
  {
    sleep(1);
  }
  return 0;
}
