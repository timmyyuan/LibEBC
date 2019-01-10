#pragma once

#include <memory>
#include <string>

namespace ebc {
class EmbeddedFile;
class EmbeddedFileFactory {
 public:
  static std::unique_ptr<EmbeddedFile> CreateEmbeddedFile(std::string file);
  static std::unique_ptr<EmbeddedFile> CreateEmbeddedFile(std::string file, std::string fileType);
  static std::unique_ptr<EmbeddedFile> CreateEmbeddedFile(char *buffer, size_t bufferSize);
  static std::unique_ptr<EmbeddedFile> CreateEmbeddedFile(char *buffer, size_t bufferSize, std::string fileType);
};
}
