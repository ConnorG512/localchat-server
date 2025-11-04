#include "server/connector.h"

#include <cerrno>
#include <cstring>
#include <format>
#include <stdexcept>

Network::Connector::Connector(const int& file_descriptor, const addrinfo* const socket_address)
{
  initConnector(file_descriptor, socket_address);
}

void Network::Connector::initConnector(const int& file_descriptor, const addrinfo* const socket_address) const
{
  if (const int result = connect(file_descriptor, socket_address->ai_addr, socket_address->ai_addrlen); result == -1)
  {
    throw std::runtime_error(std::format("[connector.cpp] Cannot conenct to socket! {}.", strerror(errno)));
  }
}
