cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML packages and they are required!
find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

# find all cpp files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Make executable
add_executable(TicTacToe ${SOURCES})

# Include h files
target_include_directories(TicTacToe PUBLIC include)

# Link SFML modules
target_link_libraries(TicTacToe sfml-graphics sfml-window sfml-system sfml-audio)