# LibXml2 Dependency
find_package(PkgConfig)
pkg_check_modules(LIBXML2 REQUIRED libxml-2.0 IMPORTED_TARGET)

include_directories(${LIBXML2_INCLUDE_DIRS})

# Test source files
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp)

# Create test binary
add_executable(ebctest ${SOURCE_FILES})
target_link_libraries(ebctest ebc ${LIBXML2_LIBRARIES})
target_include_directories(ebctest PRIVATE "catch")

# Use C++14 for tests
set_property(TARGET ebctest PROPERTY CXX_STANDARD 14)

# Enable ctest
enable_testing(true)
add_test(ebctest ebctest)
