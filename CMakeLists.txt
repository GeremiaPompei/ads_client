cmake_minimum_required(VERSION 3.0)

project(ads_client)

add_executable(ads_client main.cpp)

install(TARGETS ads_client RUNTIME DESTINATION bin)
