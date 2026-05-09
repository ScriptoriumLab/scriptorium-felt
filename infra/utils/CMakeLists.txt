add_library(modian_common_infra_utils STATIC
    src/string_utils.cpp
)

target_include_directories(modian_common_infra_utils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(modian::common::infra::utils ALIAS modian_common_infra_utils)
