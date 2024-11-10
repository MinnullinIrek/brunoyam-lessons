cmake_minimum_required(VERSION 3.16)

project(vectors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vectors
    src/main.cpp
    src/utils/vec.hpp
    src/utils/subscriber.h
    src/utils/subscriber.cpp
)

add_subdirectory(googletest)
add_subdirectory(test)

include(GNUInstallDirs)
install(TARGETS vectors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
