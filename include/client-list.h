#include <vector>
#include "template/linux-fd.h"

class ClientList {
  public:
    ClientList() = default;

  private:
    std::vector<LinuxFd<int>> connected_clients_ {};
};
