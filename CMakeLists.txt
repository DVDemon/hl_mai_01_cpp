cmake_minimum_required(VERSION 3.10)

project(hl_mai_01 C CXX)

SET (EXAMPLE_BINARY "hl_mai_01")

find_package(GTest REQUIRED)
find_package(Threads)

add_executable(${EXAMPLE_BINARY} main.cpp new_lib.cpp)
add_executable(gtests tests.cpp)
add_library(library config.cpp)

target_include_directories(${EXAMPLE_BINARY} PRIVATE "${CMAKE_BINARY_DIR}")
target_include_directories(library PRIVATE "${CMAKE_BINARY_DIR}")
target_include_directories(gtests PRIVATE "${CMAKE_BINARY_DIR}")

target_compile_options(${EXAMPLE_BINARY} PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(library PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(gtests PRIVATE -Wall -Wextra -pedantic -Werror )

target_link_libraries(${EXAMPLE_BINARY} PRIVATE library ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(gtests PRIVATE library ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(${EXAMPLE_BINARY} library gtests PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${EXAMPLE_BINARY} library gtests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

install(TARGETS ${EXAMPLE_BINARY} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT Dmitriy.Dzyuba@mts.ru)
include(CPack)

enable_testing()
add_test(gtests gtests)
