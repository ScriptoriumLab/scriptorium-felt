add_library(modian_common_core_protocol STATIC)

if (WIN32)
    target_sources(modian_common_core_protocol PRIVATE
        src/v1/input/win/key_event.cpp
    )
endif()

target_include_directories(modian_common_core_protocol PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(modian::common::core::protocol ALIAS modian_common_core_protocol)
