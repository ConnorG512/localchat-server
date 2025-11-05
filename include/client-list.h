#include "linux-fd.h"

#include <vector>

class ClientList {
  public:
    ClientList();
    
    void append(LinuxFd client);

  private:
    std::vector<LinuxFd> connected_clients_;
};
