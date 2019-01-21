add_executable(shell-app main.cpp environment.cpp node.cpp aStar.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
