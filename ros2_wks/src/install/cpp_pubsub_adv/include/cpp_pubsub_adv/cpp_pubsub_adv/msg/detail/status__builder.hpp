// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_pubsub_adv:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__BUILDER_HPP_
#define CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cpp_pubsub_adv/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cpp_pubsub_adv
{

namespace msg
{

namespace builder
{

class Init_Status_nivel
{
public:
  explicit Init_Status_nivel(::cpp_pubsub_adv::msg::Status & msg)
  : msg_(msg)
  {}
  ::cpp_pubsub_adv::msg::Status nivel(::cpp_pubsub_adv::msg::Status::_nivel_type arg)
  {
    msg_.nivel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_pubsub_adv::msg::Status msg_;
};

class Init_Status_estado
{
public:
  Init_Status_estado()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_nivel estado(::cpp_pubsub_adv::msg::Status::_estado_type arg)
  {
    msg_.estado = std::move(arg);
    return Init_Status_nivel(msg_);
  }

private:
  ::cpp_pubsub_adv::msg::Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_pubsub_adv::msg::Status>()
{
  return cpp_pubsub_adv::msg::builder::Init_Status_estado();
}

}  // namespace cpp_pubsub_adv

#endif  // CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__BUILDER_HPP_
