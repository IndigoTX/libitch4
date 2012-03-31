#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>

#include <itch_parser.hh>
#include <endian_conversion.hh>

#include "message_dispatcher.hh"


using namespace std;
using namespace Itch4;


int main(int argc, char *argv[])
{
  if (argc < 1)
  {
    cout << "First argument must be a file of input messages" << endl;
    return 1;
  }
   
  ifstream file (argv[1], ios::in|ios::binary|ios::ate);

  ifstream::pos_type size;

  if (file.is_open())
  {
    size = file.tellg();
    file.seekg(0, ios::beg);

    int16_t packet_length;

    Buffer b;
    b.reserve(Itch4::LARGEST_MESSAGE); 

    Message msg;
    Parser_state p_state;

    int counter = 0; 

    while(file.good())
    {
        // Parse soupBinTCP
        // Get the packet length
        file.read(reinterpret_cast<char*>(&packet_length), 2);
        packet_length = Itch4::network_to_host_16(packet_length); 

        // Get the payload (message)
        file.read(reinterpret_cast<char*>(&b.front()), packet_length);

        
        // Parse the message
        p_state = parse_buffer(b, msg);
 
        switch(p_state)
        {
            case PS_SUCCESS:
                msg.dispatch(message_dispatcher);
                break;
            case PS_NEED_MORE: cout << "need more" << endl; break;
            case PS_PARSE_ERROR: cout << "parse error" << endl; exit(1); break;
            default: break;
        }
        counter++;
    }
    cout << counter << endl;

    // close the file
    file.close();
  }
  else cout << "Unable to open file";

  return 0;

}
