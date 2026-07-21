add_library(scriptorium_felt_core_logger STATIC
    src/console_logger.cpp
    src/logger_service.cpp
)

target_include_directories(scriptorium_felt_core_logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(scriptorium::felt::core::logger ALIAS scriptorium_felt_core_logger)
