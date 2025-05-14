# To generate installer
# cmake -S . -B build
# cmake --build build --config Release
# cpack --config build/CPackConfig.cmake

# To compile with G++
# mkdir build
# cd build
# cmake -G "MinGW Makefiles" ..
# mingw32-make

# Top-level CMake configuration
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(AdlerDatabase LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/headers
    C:/libraries/json/include
    C:/libraries/webview/core/include
    C:/libraries/WebView2/build/native/include
)

set(SRCS
    src/logger.cpp
    src/APIClient.cpp
    src/main.cpp
)

if (APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRCS})
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/src/Info.plist
    )
else()
    add_executable(${PROJECT_NAME} WIN32 ${SRCS} src/main.exe.manifest)
endif()

# Windows-specific libraries
if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32 version shlwapi)
endif()

# Web content copy
set(HTML_SOURCE_DIR "${CMAKE_SOURCE_DIR}/web")
set(HTML_DEST_DIR "${CMAKE_BINARY_DIR}/web")
file(COPY ${HTML_SOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})

# Install targets
include(InstallRequiredSystemLibraries)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/web DESTINATION .)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/headers DESTINATION include)

# CPack packaging configuration
set(CPACK_GENERATOR "NSIS")  # Or "ZIP" for a portable version
set(CPACK_PACKAGE_NAME "AdlerDatabase")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_EXECUTABLES "${PROJECT_NAME}" "Adler Database")
include(CPack)
