add_library(scriptorium_felt_infra_utils STATIC
    src/string_utils.cpp
)

target_include_directories(scriptorium_felt_infra_utils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(scriptorium::felt::infra::utils ALIAS scriptorium_felt_infra_utils)
