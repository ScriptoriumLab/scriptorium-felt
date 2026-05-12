include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(spdlog)
add_compile_definitions(SPDLOG_HEADER_ONLY)

add_library(modian_common_infra_logger STATIC
    src/spdlog_logger.cpp
)

target_include_directories(modian_common_infra_logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# TODO: should consider the public or private
target_link_libraries(modian_common_infra_logger
    PUBLIC modian::common::core::logger
    PUBLIC spdlog::spdlog
)

add_library(modian::common::infra::logger ALIAS modian_common_infra_logger)
