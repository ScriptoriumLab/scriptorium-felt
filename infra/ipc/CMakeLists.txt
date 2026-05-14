add_library(modian_common_infra_ipc STATIC)

if (WIN32)
    target_sources(modian_common_infra_ipc PRIVATE
        src/win/sync_named_pipe_server.cpp
        src/win/async_named_pipe_server.cpp
        src/win/ipc_server_factory.cpp
    )
endif()

target_include_directories(modian_common_infra_ipc PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(modian_common_infra_ipc
    PUBLIC
        modian::common::core::ipc
    PRIVATE
        modian::common::core::logger
        modian::common::infra::utils
)

add_library(modian::common::infra::ipc ALIAS modian_common_infra_ipc)
