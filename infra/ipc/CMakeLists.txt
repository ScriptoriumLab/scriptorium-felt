add_library(scriptorium_felt_infra_ipc STATIC)

if (WIN32)
    target_sources(scriptorium_felt_infra_ipc PRIVATE
        src/win/sync_named_pipe_server.cpp
        src/win/sync_named_pipe_client.cpp
        src/win/async_named_pipe_server.cpp
        src/win/ipc_server_factory.cpp
        src/win/ipc_client_factory.cpp
    )
endif()

target_include_directories(scriptorium_felt_infra_ipc PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(scriptorium_felt_infra_ipc
    PUBLIC
        scriptorium::felt::core::ipc
    PRIVATE
        scriptorium::felt::core::logger
        scriptorium::felt::infra::utils
)

add_library(scriptorium::felt::infra::ipc ALIAS scriptorium_felt_infra_ipc)
