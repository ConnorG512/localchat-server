#include <netdb.h>
namespace Network
{
class Addrinfo
{
public:
  Addrinfo(const char* port_number = "40050");
  ~Addrinfo();
  
  [[nodiscard]] const addrinfo* const GetAddrInfo() const;

private:
  void initAddrinfo(const char* port_number);

  struct addrinfo addr_hints_{};
  struct addrinfo* server_info_{nullptr};

};
} // namespace Network
