#include <iostream>
#include <stdexcept>

#include <vector>
#include <list>

#include <ip_printer/ip_printer.h>

int main(int /*argc*/, char const * /*argv*/[])
{
  try {
    print_ip(char(-1));
    print_ip(short(0));
    print_ip(int(2130706433));
    print_ip(long(8875824491850138409));
    print_ip(std::string("192.168.1.1"));
    print_ip(std::vector< int >{1, 2, 3, 4});
    print_ip(std::list< int >{1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999});
    // print_ip(std::make_tuple(1, 2, 3));
  }
  catch(std::exception const & e) {
    std::cerr << e.what() << std::endl;
    throw;
  }


  std::cout.flush();
  return 0;
}
