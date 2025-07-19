// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cpp_pubsub_adv:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__STRUCT_HPP_
#define CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cpp_pubsub_adv__msg__Status __attribute__((deprecated))
#else
# define DEPRECATED__cpp_pubsub_adv__msg__Status __declspec(deprecated)
#endif

namespace cpp_pubsub_adv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Status_
{
  using Type = Status_<ContainerAllocator>;

  explicit Status_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->estado = "";
      this->nivel = 0l;
    }
  }

  explicit Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : estado(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->estado = "";
      this->nivel = 0l;
    }
  }

  // field types and members
  using _estado_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _estado_type estado;
  using _nivel_type =
    int32_t;
  _nivel_type nivel;

  // setters for named parameter idiom
  Type & set__estado(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->estado = _arg;
    return *this;
  }
  Type & set__nivel(
    const int32_t & _arg)
  {
    this->nivel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cpp_pubsub_adv::msg::Status_<ContainerAllocator> *;
  using ConstRawPtr =
    const cpp_pubsub_adv::msg::Status_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub_adv::msg::Status_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub_adv::msg::Status_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cpp_pubsub_adv__msg__Status
    std::shared_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cpp_pubsub_adv__msg__Status
    std::shared_ptr<cpp_pubsub_adv::msg::Status_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_ & other) const
  {
    if (this->estado != other.estado) {
      return false;
    }
    if (this->nivel != other.nivel) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_

// alias to use template instance with default allocator
using Status =
  cpp_pubsub_adv::msg::Status_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cpp_pubsub_adv

#endif  // CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__STRUCT_HPP_
