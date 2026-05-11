add_library(modian_common_core_protocol INTERFACE)

target_include_directories(modian_common_core_protocol INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(modian_common::core::protocol ALIAS modian_common_core_protocol)
