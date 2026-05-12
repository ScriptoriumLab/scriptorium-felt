add_library(modian_common_core_logger STATIC
    src/console_logger.cpp
    src/logger_service.cpp
)

target_include_directories(modian_common_core_logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(modian::common::core::logger ALIAS modian_common_core_logger)
