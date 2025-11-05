#pragma once

#include "linux-fd.h"

#include <memory>
#include <netdb.h>
#include <unistd.h>

namespace Networking
{
class Server
{
public:
  Server(const char* const port_number = "40050");

  [[nodiscard]] int acceptConnection() const;

private:
  LinuxFd socket_{};
  std::unique_ptr<addrinfo, decltype(&freeaddrinfo)> addr_ {nullptr, &freeaddrinfo}; 
};
} // namespace Network
