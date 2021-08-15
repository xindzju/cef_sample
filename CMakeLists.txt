cmake_minimum_required(VERSION 3.10)
set(TARGET_NAME cef_sample)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_definitions(-D_ITERATOR_DEBUG_LEVEL=0) 

file(GLOB CEF_SAMPLE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

include_directories(./cef)
include_directories(./src)

link_directories(./cef/Debug) #cef dll 
# link_directories(./cef/Release) #cef dll 
link_directories(./cef/wrapper/debug) #cef dll c++ wrapper
# link_directories(./cef/wrapper/release) #cef dll c++ wrapper


add_executable(${TARGET_NAME} WIN32 ${CEF_SAMPLE_SRCS})
target_link_libraries(${TARGET_NAME} libcef cef_sandbox libcef_dll_wrapper)

#copy files needed by cef_sample
add_custom_target(CopyTask
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/cef/Resources ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/cef/Debug ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug
    COMMENT "Copying needed files from cef..."
    )

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND "mt.exe" -manifest \"$(TargetDir)..\\..\\cef_sample.manifest\" -outputresource:"$(TargetDir)$(TargetFileName)"\;\#1
    COMMENT "Adding manifest..." 
)