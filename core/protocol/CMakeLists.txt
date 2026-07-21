add_library(scriptorium_felt_core_protocol STATIC)

if (WIN32)
    target_sources(scriptorium_felt_core_protocol PRIVATE
        src/v1/input/win/key_event.cpp
    )
endif()

target_include_directories(scriptorium_felt_core_protocol PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(scriptorium::felt::core::protocol ALIAS scriptorium_felt_core_protocol)
