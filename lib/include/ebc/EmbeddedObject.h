#pragma once

#include "ebc/EmbeddedFile.h"

#include <string>

namespace ebc {
class EmbeddedObject : public EmbeddedFile {
 public:
  EmbeddedObject(std::string file) : EmbeddedFile(std::move(file), EmbeddedFile::Type::Object) {}
  EmbeddedObject(char *buffer, size_t bufferSize) : EmbeddedFile(buffer, bufferSize, EmbeddedFile::Type::Object) {}
  ~EmbeddedObject() = default;
};
}
