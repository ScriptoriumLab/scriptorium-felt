include(FetchContent)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_library(scriptorium_felt_service_protocol STATIC
    src/input_protocol_service.cpp
    src/ui_protocol_service.cpp
)

target_link_libraries(scriptorium_felt_service_protocol
    PUBLIC
        scriptorium::felt::core::protocol
    PRIVATE
        nlohmann_json::nlohmann_json
        scriptorium::felt::core::logger
)

target_include_directories(scriptorium_felt_service_protocol PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(scriptorium::felt::service::protocol ALIAS scriptorium_felt_service_protocol)
