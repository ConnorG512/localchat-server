#include "server/server.h"

#include <cerrno>
#include <cstring>
#include <format>
#include <memory>
#include <netdb.h>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>

Networking::Server::Server(const char* const port_number)
{
  const addrinfo hints{
      .ai_flags = AI_PASSIVE,
      .ai_family = AF_UNSPEC,
      .ai_socktype = SOCK_STREAM,
  };

  if (const int result = getaddrinfo(nullptr, port_number, &hints, std::out_ptr(addr_)); result == -1)
  {
    throw std::runtime_error(std::format("Failed to get address info! {}.", strerror(errno)));
  }

  if (socket_.fd = socket(addr_->ai_family, addr_->ai_socktype, addr_->ai_protocol); socket_.fd == -1)
  {
    throw std::runtime_error(std::format("Failed to get scoket! {}.", strerror(errno)));
  }

  if( const int result = bind(socket_.fd, addr_->ai_addr, addr_->ai_addrlen); result == -1)
  {
    throw std::runtime_error(std::format("Failed to get scoket! {}.", strerror(errno)));
  }

  if(const int result = listen(socket_.fd, 5); result == -1)
  {
    throw std::runtime_error(std::format("Failed to Listen! {}.", strerror(errno)));
  }
}
