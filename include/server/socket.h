#pragma once

#include <netdb.h>

namespace Network
{
class Socket
{
public:
  explicit Socket(const addrinfo* const address_info);
  ~Socket();

  Socket(const Socket& socket) = delete;            // Delete copy constructor.
  Socket& operator=(const Socket& socket) = delete; // Delete copy assignment constructor.

  [[nodiscard]] const int& GetFileDescriptor() const;

private:
  void initSocket(const addrinfo* const address_info);

  int file_descriptor_ {-1};
};
} // namespace Network
