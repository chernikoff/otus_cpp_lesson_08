#ifndef IP_PRINTER_H
#define IP_PRINTER_H

#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <iterator>

namespace detail {

template< typename T >
struct is_container : public std::false_type {};

template< typename T, typename Allocator >
struct is_container< std::vector< T, Allocator > > : public std::true_type {};

template< typename T, typename Allocator >
struct is_container< std::list< T, Allocator > > : public std::true_type {};

template< typename T >
struct is_tuple : public std::false_type {};

template< typename ... Ts >
struct is_tuple< std::tuple< Ts ... > > : public std::true_type {};

} // namespace detail

/// @brief Function for print ip address
/// @tparam T should be integral type
/// @param value printable value
template< typename T >
typename std::enable_if< std::is_integral< T >::value, void >::type
print_ip(T const & value)
{
  for (size_t i = 0, bytes_count = sizeof(value);
       i != bytes_count; ++i) {
    if (i != 0) {
      std::cout << ".";
    }
    std::cout << std::to_string((value >> ((bytes_count - i - 1) * 8) & 0xFF));
  }
  std::cout << std::endl;
}

/// @brief Function for print ip address
/// @tparam T should be string
/// @param value printable value
template< typename T >
typename std::enable_if< std::is_same< T, std::string >::value, void>::type
print_ip(T const & value)
{
  std::cout << value << std::endl;
}

/// @brief Function for print ip address
/// @tparam T should be container type
/// @param value printable value
template< typename T >
typename std::enable_if< detail::is_container< T >::value, void >::type
print_ip(T const & value)
{
  for (auto begin = std::begin(value), end = std::end(value), it = begin;
       it != end; ++it) {
    if (it != begin) {
      std::cout << ".";
    }
    std::cout << *it;
  }
  std::cout << std::endl;
}

template< typename T >
typename std::enable_if< detail::is_tuple<T>::value, void >::type
print_ip(T const &)
{
  std::cout << "tuple\n";
}




#endif /* IP_PRINTER_H */

