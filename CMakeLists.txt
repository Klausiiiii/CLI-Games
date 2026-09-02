cmake_minimum_required(VERSION 3.10)
project(Games LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)

add_executable(games
		src/main.cpp
		src/games/snake/snake_logic.cpp
)

target_include_directories(games PRIVATE src)

target_compile_options(games PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(games PRIVATE ${CURSES_LIBRARIES})
