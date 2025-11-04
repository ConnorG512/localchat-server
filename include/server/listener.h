#pragma once

namespace Network
{
class Listener
{
public:
  Listener(const int& file_descriptor, const int back_log = 5);
  void initListen(const int& file_descriptor, const int back_log) const;
};
} // namespace Network
