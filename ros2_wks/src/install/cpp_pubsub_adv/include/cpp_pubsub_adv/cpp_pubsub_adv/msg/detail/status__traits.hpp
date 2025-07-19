// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cpp_pubsub_adv:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__TRAITS_HPP_
#define CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cpp_pubsub_adv/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cpp_pubsub_adv
{

namespace msg
{

inline void to_flow_style_yaml(
  const Status & msg,
  std::ostream & out)
{
  out << "{";
  // member: estado
  {
    out << "estado: ";
    rosidl_generator_traits::value_to_yaml(msg.estado, out);
    out << ", ";
  }

  // member: nivel
  {
    out << "nivel: ";
    rosidl_generator_traits::value_to_yaml(msg.nivel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: estado
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estado: ";
    rosidl_generator_traits::value_to_yaml(msg.estado, out);
    out << "\n";
  }

  // member: nivel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nivel: ";
    rosidl_generator_traits::value_to_yaml(msg.nivel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cpp_pubsub_adv

namespace rosidl_generator_traits
{

[[deprecated("use cpp_pubsub_adv::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cpp_pubsub_adv::msg::Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  cpp_pubsub_adv::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cpp_pubsub_adv::msg::to_yaml() instead")]]
inline std::string to_yaml(const cpp_pubsub_adv::msg::Status & msg)
{
  return cpp_pubsub_adv::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cpp_pubsub_adv::msg::Status>()
{
  return "cpp_pubsub_adv::msg::Status";
}

template<>
inline const char * name<cpp_pubsub_adv::msg::Status>()
{
  return "cpp_pubsub_adv/msg/Status";
}

template<>
struct has_fixed_size<cpp_pubsub_adv::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cpp_pubsub_adv::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cpp_pubsub_adv::msg::Status>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__TRAITS_HPP_
