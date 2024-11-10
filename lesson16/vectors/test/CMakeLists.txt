
# set(CMAKE_CXX_STANDART 17)
#set(CMAKE_CXX_STANDART_REQUIRED ON)
add_executable(tests)
target_sources(tests PRIVATE 
  ../src/utils/subscriber.cpp
  test_main.cpp
#   test_cash.cpp
  )
target_compile_features(tests PRIVATE cxx_std_17)


target_link_libraries(tests PRIVATE gtest_main gmock_main)
target_include_directories(tests PUBLIC 
  ../googletest/googletest/include/
  ../googletest/googlemock/include/
  ../src/utils/  
)




