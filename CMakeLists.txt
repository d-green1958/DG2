cmake_minimum_required(VERSION 3.10)

project(DG2 LANGUAGES CXX)

# Create a header-only interface library
add_library(DG2 INTERFACE)

# Provide a namespaced target
add_library(DG2::DG2 ALIAS DG2)

# Require C++17
target_compile_features(DG2 INTERFACE cxx_std_20)

# Include directories
target_include_directories(DG2 INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
