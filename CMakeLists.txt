cmake_minimum_required(VERSION 3.10)
enable_testing()

project(bowling)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FLAGS -Wall -Wextra -Werror -Wconversion -pedantic -g)
set(SANITS -fsanitize=address -fsanitize=undefined)
set(SRC
    File.cpp
    Game.cpp)
set(TEST_SRC
    File-ut.cpp
    Game-ut.cpp)

#####################################################################
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
#####################################################################

add_library(${PROJECT_NAME}-lib ${SRC})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_link_options(${PROJECT_NAME}-lib PRIVATE ${SANITS})

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib)
target_link_options(${PROJECT_NAME} PRIVATE ${SANITS})

add_executable(${PROJECT_NAME}-ut ${TEST_SRC})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC gtest_main)
target_link_options(${PROJECT_NAME}-ut PRIVATE ${SANITS})

add_test(NAME bowling-ut COMMAND ${PROJECT_NAME}-ut)
