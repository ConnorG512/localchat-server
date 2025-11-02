#include <cerrno>
#include <cstring>
#include <format>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

int main() {
  
  struct addrinfo hints{};
  struct addrinfo *servinfo{};
  struct sockaddr_storage their_addr{};
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(nullptr, "40050", &hints, &servinfo);
  if(status != 0)
  {
    throw std::runtime_error(std::format("Failed to create addrinfo! {}.", gai_strerror(status)));
  }

  const int socket_fd = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
  if(socket_fd == -1)
  {
    throw std::runtime_error(std::format("Failed to create socket! {}.", strerror(errno)));
  }

  if(const int bind_result = bind(socket_fd, servinfo->ai_addr, servinfo->ai_addrlen); bind_result == -1)
  {
    throw std::runtime_error(std::format("Failed to bind! {}.", strerror(errno)));
  }

  if(const int listen_result = listen(socket_fd, 5); listen_result == -1)
  {
    throw std::runtime_error(std::format("Failed to listen! {}.", strerror(errno)));
  }

  socklen_t addr_size{sizeof(their_addr)};
  auto new_fd{accept(socket_fd, reinterpret_cast<sockaddr*>(&their_addr), &addr_size)};

  while(true)
  {
    sleep(1);
  }

  
  freeaddrinfo(servinfo);
  close(socket_fd);
  return 0;
}
