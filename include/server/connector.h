#pragma once

#include <netdb.h>
#include <sys/socket.h>

namespace Network
{
class Connector
{
public:
  Connector(const int& file_descriptor, const addrinfo* const socket_address);
  ~Connector() = default;

private:
  void initConnector(const int& file_descriptor, const addrinfo* const socket_address) const;
};
} // namespace Network
