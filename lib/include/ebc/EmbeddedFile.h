#pragma once

#include <string>
#include <vector>

namespace ebc {
class EmbeddedFile {
 public:
  enum class Type {
    Bitcode,
    Exports,
    File,
    LTO,
    Object,
    Xar,
  };

  enum class CommandSource {
    Clang,
    Swift,
  };

  EmbeddedFile(std::string name);
  EmbeddedFile(char *buffer, size_t bufferSize);
  virtual ~EmbeddedFile();

  std::string GetName() const;
  std::pair<const char *, size_t> GetRawBuffer() const;

  /// Get all commands passed to the compiler to create this embedded file.
  ///
  /// @return A vector of strings with the clang front-end commands.
  const std::vector<std::string>& GetCommands() const;

  /// Set all commands passed to the compiler to create this embedded file.
  ///
  /// @param commands A vector of strings with the clang front-end
  ///                 commands.
  void SetCommands(const std::vector<std::string>& commands, CommandSource source);

  /// Remove the underlying file from the file system.
  void Remove() const;

  Type GetType() const;

  CommandSource GetCommandSource() const;

 protected:
  EmbeddedFile(std::string name, Type type);
  EmbeddedFile(char *buffer, size_t, Type type);
 private:
  char *_buffer;
  size_t _bufferSize;
  std::string _name;
  Type _type;
  std::vector<std::string> _commands;
  CommandSource _commandSource;
};

inline bool operator==(const EmbeddedFile& lhs, const EmbeddedFile& rhs) {
  return lhs.GetName() == rhs.GetName();
}
}
