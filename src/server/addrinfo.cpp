#include "server/addrinfo.h"

#include <cassert>
#include <cstring>
#include <format>
#include <netdb.h>
#include <stdexcept>
#include <sys/socket.h>

Network::Addrinfo::Addrinfo(const char* port_number)

{
  initAddrinfo(port_number);
}

Network::Addrinfo::~Addrinfo()
{
  freeaddrinfo(server_info_);
}

void Network::Addrinfo::initAddrinfo(const char* port_number)
{
  addr_hints_.ai_family = AF_INET;
  addr_hints_.ai_socktype = SOCK_STREAM;
  addr_hints_.ai_flags = AI_PASSIVE;

  if(const int result = getaddrinfo(nullptr, port_number, &addr_hints_, &server_info_); result != 0)
  {
    throw std::runtime_error(std::format("[addrinfo.cpp] Failed to get address info! {}.", strerror(result)));
  }
}

const addrinfo* const Network::Addrinfo::GetAddrInfo() const
{
  assert(server_info_ != nullptr);
  return server_info_;
}
