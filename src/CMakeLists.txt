cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(wx_cmake_template_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prevent conflicts in Windows headers
add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX)


# hack for buggy CMake's FindwxWidgets script
if(DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base xml)

include_directories("C:/Adler_Database/src")
include_directories("C:/Adler_Database/headers")
include_directories("C:/libraries/json/include")
include_directories("C:/libraries/webview/core/include")
include_directories("C:/libraries/WebView2/build/native/include")

# Ensure the current source directory is included
include_directories(${CMAKE_SOURCE_DIR})

# Set source files - include both main.cpp and logger.cpp
set(SRCS main.cpp logger.cpp caller.cpp)

# Include wxWidgets configuration
include(${wxWidgets_USE_FILE})

if(APPLE)
    # Create bundle on Apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # WIN32 is needed for Windows to look for WinMain instead of the main function
    add_executable(main WIN32 ${SRCS} main.exe.manifest)
endif()

# Link wxWidgets, MySQL, PyBind11, and Python libraries
target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})