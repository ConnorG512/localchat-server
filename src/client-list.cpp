#include "client-list.h"

ClientList::ClientList()
{
}

void ClientList::append(LinuxFd client)
{
  connected_clients_.push_back(std::move(client));
}
