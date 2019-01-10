#pragma once

#include "ebc/EmbeddedFile.h"

#include <string>

namespace ebc {
class EmbeddedExports : public EmbeddedFile {
 public:
  EmbeddedExports(std::string file) : EmbeddedFile(std::move(file), EmbeddedFile::Type::Exports) {}
  EmbeddedExports(char *buffer, size_t bufferSize) : EmbeddedFile(buffer, bufferSize, EmbeddedFile::Type::Exports) {}
  ~EmbeddedExports() = default;
};
}
