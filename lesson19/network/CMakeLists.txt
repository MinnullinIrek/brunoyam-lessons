cmake_minimum_required(VERSION 3.11)

project(network CXX)
set(CMAKE_CXX_STANDARD 20)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)

# Проект содержит единственный исходный файл src/main.cpp
add_executable(network src/main.cpp)
# Просим компоновщик подключить библиотеку для поддержки потоков
# target_link_libraries(network PRIVATE Threads::Threads)

target_include_directories(network PUBLIC 
  src/
  asio/asio/include/
)

add_compile_definitions(ASIO_STANDALONE)
