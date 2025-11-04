#pragma once

#include <netdb.h>
#include <sys/socket.h>

namespace Network
{
class Acceptor
{
public:
  Acceptor(const int& file_descriptor);
  ~Acceptor();

  Acceptor(const Acceptor& acceptor) = delete;            // Delete copy constructor.
  Acceptor& operator=(const Acceptor& acceptor) = delete; // Delete copy assignment constructor.

private:
  void initAccept(const int& file_descriptor);

  sockaddr_storage client_address_{};
  socklen_t address_size_{sizeof(client_address_)};
  int client_file_descriptor_{-1};
};
} // namespace Network
