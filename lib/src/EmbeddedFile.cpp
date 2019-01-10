#include "ebc/EmbeddedFile.h"

#include <cstdio>
#include <utility>
#include <ebc/EmbeddedFile.h>

namespace ebc {

EmbeddedFile::EmbeddedFile(std::string name) : _buffer(nullptr), _bufferSize(0), _name(std::move(name)), _type(EmbeddedFile::Type::File) {}
EmbeddedFile::EmbeddedFile(std::string name, EmbeddedFile::Type type) : _buffer(nullptr), _bufferSize(0), _name(std::move(name)), _type(type) {}
EmbeddedFile::EmbeddedFile(char *buffer, size_t bufferSize) : _buffer(buffer), _bufferSize(bufferSize), _name(), _type(EmbeddedFile::Type::File) {}
EmbeddedFile::EmbeddedFile(char *buffer, size_t bufferSize, EmbeddedFile::Type type) : _buffer(buffer), _bufferSize(bufferSize), _name(), _type(type) {}

EmbeddedFile::~EmbeddedFile() {
  if (_buffer != nullptr) {
    free(_buffer);
  }
}

std::string EmbeddedFile::GetName() const {
  return _name;
}

std::pair<const char *, size_t> EmbeddedFile::GetRawBuffer() const {
  return std::make_pair(_buffer, _bufferSize);
}

const std::vector<std::string>& EmbeddedFile::GetCommands() const {
  return _commands;
}

void EmbeddedFile::SetCommands(const std::vector<std::string>& commands, CommandSource source) {
  if (!commands.empty()) {
    _commands = commands;
    _commandSource = source;
  }
}

EmbeddedFile::Type EmbeddedFile::GetType() const {
  return _type;
}

void EmbeddedFile::Remove() const {
  std::remove(_name.c_str());
}

EmbeddedFile::CommandSource EmbeddedFile::GetCommandSource() const {
  return _commandSource;
}

}  // namespace ebc
