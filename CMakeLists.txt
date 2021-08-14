cmake_minimum_required(VERSION 3.10)
set(TARGET_NAME cef_sample)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB CEF_SAMPLE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

include_directories(./cef)
include_directories(./src)

link_directories(./cef/Debug) #cef dll 
# link_directories(./cef/Release) #cef dll 
link_directories(./cef/wrapper/debug) #cef dll c++ wrapper
# link_directories(./cef/wrapper/release) #cef dll c++ wrapper

add_executable(${TARGET_NAME} WIN32 ${CEF_SAMPLE_SRCS})
target_link_libraries(${TARGET_NAME} libcef cef_sandbox libcef_dll_wrapper)

