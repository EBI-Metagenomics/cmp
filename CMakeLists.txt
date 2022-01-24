cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(
  cmp
  VERSION 1.19.1
  LANGUAGES C
)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("${CMAKE_CURRENT_LIST_DIR}/external/cmake-boilerplate/cbp.cmake")
cbp_set_rpath()

add_library(
  cmp
  src/cmp.c
  src/cmp_ext.c
)
add_library(CMP::cmp ALIAS cmp)

cbp_hide_functions(cmp)
cbp_set_warning_flags()
cbp_generate_export_header(cmp EXPORT_FILE)

target_include_directories(
  cmp
  PUBLIC $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
set_target_properties(cmp PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(cmp PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
target_compile_features(cmp PRIVATE c_std_11)
target_compile_definitions(cmp PRIVATE $<$<BOOL:${WIN32}>:_CRT_NONSTDC_NO_DEPRECATE>)
target_compile_definitions(cmp PRIVATE $<$<BOOL:${WIN32}>:__extension__>)
target_compile_options(cmp PRIVATE ${WARNING_FLAGS})

cbp_install(cmp MERGED)
install(FILES ${EXPORT_FILE} ${VERSION_FILE} DESTINATION include/cmp)
