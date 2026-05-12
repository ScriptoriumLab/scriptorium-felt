include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    modian_common_tests
    test_main.cpp
    infra/utils/string_utils_test.cpp
    service/protocol/input_protocol_service_test.cpp
    service/protocol/ui_protocol_service_test.cpp
)

target_link_libraries(
    modian_common_tests
    modian::common::infra::utils
    modian::common::service::protocol
    gtest_main
    gmock_main
)
