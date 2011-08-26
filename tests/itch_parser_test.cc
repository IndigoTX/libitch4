#include <iostream>

#include <itch_parser.hh>

using namespace std;
using namespace Itch4;

int main() {
  Buffer b;
  Message msg;
  
  Parser_state p_state = parse_buffer(b, msg);

  switch(p_state) {
  case PS_SUCCESS:
    cout << "Success!" << endl;
    break;
  case PS_NEED_MORE:
    cout << "Need more..." << endl;
    break;
  case PS_PARSE_ERROR:
    cout << "There was a parse error" << endl;
    break;
  default:
    cout << "Dunno.." << endl;
  }
  
}
