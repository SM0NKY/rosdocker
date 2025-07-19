// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_pubsub_adv:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__STRUCT_H_
#define CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'estado'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Status in the package cpp_pubsub_adv.
typedef struct cpp_pubsub_adv__msg__Status
{
  rosidl_runtime_c__String estado;
  int32_t nivel;
} cpp_pubsub_adv__msg__Status;

// Struct for a sequence of cpp_pubsub_adv__msg__Status.
typedef struct cpp_pubsub_adv__msg__Status__Sequence
{
  cpp_pubsub_adv__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_pubsub_adv__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_PUBSUB_ADV__MSG__DETAIL__STATUS__STRUCT_H_
