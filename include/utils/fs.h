#pragma once

namespace fs {

void WriteFile(const char* filename, const char* content);
[[nodiscard]] char* ReadFile(const char* filename);

}  // namespace fs
