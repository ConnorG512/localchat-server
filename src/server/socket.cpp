#include "server/socket.h"

#include <cerrno>
#include <cstring>
#include <netdb.h>
#include <stdexcept>
#include <sys/socket.h>
#include <format>
#include <unistd.h>

Network::Socket::Socket(const addrinfo* const address_info)
{
  initSocket(address_info);
}

Network::Socket::~Socket()
{
  close(file_descriptor_);
}

void Network::Socket::initSocket(const addrinfo* const address_info) const
{
  if (const int result = socket(file_descriptor_, address_info->ai_socktype, address_info->ai_protocol); result == -1)
  {
    throw std::runtime_error(std::format("[socket.cpp] Failed to create socket! {}.", strerror(errno)));
  }
}

const int& Network::Socket::GetFileDescriptor() const
{
  return file_descriptor_;
}
