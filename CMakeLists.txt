cmake_minimum_required(VERSION 3.16)

project(dec2bin)

set(MPIR_INCLUDE_DIR "C:/vcpkg/packages/mpir_x64-windows-release/include")
set(MPIR_LIBRARIES "C:/vcpkg/packages/mpir_x64-windows-release/lib/mpir.lib")

include_directories(${MPIR_INCLUDE_DIR})
link_libraries(${MPIR_LIBRARIES})

add_executable(dec2bin dec2bin.cpp)

install(TARGETS dec2bin)
