// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include <new>

#include "ForwardDeclarations.hpp"
#include "JsonValue.hpp"

namespace ArduinoJson {

class JsonBuffer {
 public:
  virtual ~JsonBuffer() {}

  JsonArray createArray();
  JsonObject createObject();
  JsonValue createValue();

  template <typename T>
  JsonValue createValue(T x) {
    JsonValue value;
    value = x;
    return value;
  }

  JsonArray parseArray(char* json);
  JsonObject parseObject(char* json);
  JsonValue parseValue(char* json);

  virtual void* alloc(size_t size) = 0;
};
}

void* operator new(size_t size, ArduinoJson::JsonBuffer* buffer);
