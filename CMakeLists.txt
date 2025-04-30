# To generate installer
# cmake -S . -B build
# cmake --build build --config Release
# cpack --config build/CPackConfig.cmake

# To compile with G++
# mkdir build
# cd build
# cmake -G "MinGW Makefiles" ..
# mingw32-make

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(AdlerDatabase LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define all necessary include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/headers
    C:/libraries/json/include
    C:/libraries/webview/core/include
    C:/libraries/WebView2/build/native/include
)

# Define a macro to avoid Windows header conflicts
add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX)

# Define the list of source files
set(SRCS
    src/logger.cpp
    src/APIClient.cpp
    src/main.cpp
)

# Add executable, handle platform-specific options
if(APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRCS})
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/src/Info.plist
    )
else()
    add_executable(${PROJECT_NAME} WIN32 ${SRCS} src/main.exe.manifest)
endif()

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32 version shlwapi)
endif()


# Define the HTML source and destination directories
set(HTML_SOURCE_DIR "${CMAKE_SOURCE_DIR}/web")
set(HTML_DEST_DIR "${CMAKE_BINARY_DIR}/web")

# Copy HTML files to build output directory
file(COPY ${HTML_SOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})

include(InstallRequiredSystemLibraries)

# Set installation target
install(TARGETS ${PROJECT_NAME}
        DESTINATION bin)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/web
        DESTINATION .)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/headers
        DESTINATION include)

# Optionally, install DLLs or config files
# install(FILES some_dependency.dll DESTINATION bin)

# Packaging setup
set(CPACK_GENERATOR "NSIS")  # Or "ZIP" for portable
set(CPACK_PACKAGE_NAME "AdlerDatabase")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_EXECUTABLES "${PROJECT_NAME}" "Adler Database")

include(CPack)