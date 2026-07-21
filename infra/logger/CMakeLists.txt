include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(spdlog)
add_compile_definitions(SPDLOG_HEADER_ONLY)

add_library(scriptorium_felt_infra_logger STATIC
    src/spdlog_logger.cpp
)

target_include_directories(scriptorium_felt_infra_logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(scriptorium_felt_infra_logger
    PRIVATE scriptorium::felt::core::logger
    PUBLIC spdlog::spdlog
)

add_library(scriptorium::felt::infra::logger ALIAS scriptorium_felt_infra_logger)
