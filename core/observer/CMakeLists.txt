add_library(modian_common_core_observer INTERFACE)

target_include_directories(modian_common_core_observer INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(modian::common::core::observer ALIAS modian_common_core_observer)
