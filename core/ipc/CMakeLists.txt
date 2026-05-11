add_library(modian_common_core_ipc INTERFACE)

target_include_directories(modian_common_core_ipc INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(modian::common::core::ipc ALIAS modian_common_core_ipc)
