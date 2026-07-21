add_library(scriptorium_felt_core_observer INTERFACE)

target_include_directories(scriptorium_felt_core_observer INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(scriptorium::felt::core::observer ALIAS scriptorium_felt_core_observer)
