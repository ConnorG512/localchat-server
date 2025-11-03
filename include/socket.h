#pragma once

#include <netdb.h>
#include <unistd.h>

class Socket
{
public:
  Socket();
  ~Socket();

  Socket(const Socket& socket) = delete;                // Delete copy constructor.
  Socket& operator=(const Socket& socket) = delete;     // Delete copy assignment constructor.

private:
  struct addrinfo m_hints{.ai_family = AF_INET, .ai_socktype = SOCK_STREAM, .ai_flags = AI_PASSIVE};
  int m_file_descriptor{-1};
};
