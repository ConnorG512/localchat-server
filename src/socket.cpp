#include "socket.h"


Socket::Socket() : m_file_descriptor{socket(m_hints.ai_family, m_hints.ai_socktype, m_hints.ai_protocol)} 
{
}

Socket::~Socket()
{
  freeaddrinfo(&m_hints);
  close(m_file_descriptor);
}
