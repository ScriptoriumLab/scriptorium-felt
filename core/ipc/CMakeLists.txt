add_library(scriptorium_felt_core_ipc INTERFACE)

target_include_directories(scriptorium_felt_core_ipc INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(scriptorium::felt::core::ipc ALIAS scriptorium_felt_core_ipc)
