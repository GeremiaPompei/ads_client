cmake_minimum_required(VERSION 3.0)

project(ads_client)

set(CMAKE_CXX_STANDARD 11)

add_executable(ads_client main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

target_link_libraries(${PROJECT_NAME} PUBLIC libAdsLib.a)
