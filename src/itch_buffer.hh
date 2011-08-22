#ifndef ITCH_BUFFER_HH
#define ITCH_BUFFER_HH

#include <itch_message_types.hh>

namespace Itch {

  /*
   * N is the maximum number of largest messages the buffer can hold
   *
   * This class is probably not legit since I'm casting to/from unsigned char/char
   */
  template <size_t N>
  class Buffer {
  public:
    char *buffer() {
    }

  private:
    unsigned char buffer_[LARGEST_MESSAGE * N];
  };
}

#endif
