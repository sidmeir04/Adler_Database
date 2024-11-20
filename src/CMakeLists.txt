cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(wx_cmake_template_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prevent conflicts in Windows headers
add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX)

# Set the Python installation directory
set(Python3_ROOT_DIR "C:/Users/oscar/AppData/Local/Programs/Python/Python313")

# hack for buggy CMake's FindwxWidgets script
if(DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base xml)

# Find Python3: Find the Python interpreter and development libraries
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
set(Python3_LIBRARIES Python3::Python)
find_package(Python3 COMPONENTS Development REQUIRED)

# Manually specify the Python library path
set(PYTHON_LIB_PATH "C:/Users/oscar/AppData/Local/Programs/Python/Python313/libs/python313.lib")

# Set the path to your Pybind11 directory
set(PYBIND11_DIR "C:/libraries/pybind11")
add_subdirectory(${PYBIND11_DIR} pybind11_build)
include_directories(${PYBIND11_DIR}/include)
include_directories(${Python3_INCLUDE_DIRS})

# MySQL Connector C++: Specify the MySQL include and library directories
set(MYSQL_CONNECTOR_DIR "C:/libraries/MySQL/MySQL_Connector_C++_9.0")
set(MYSQL_INCLUDE_DIR ${MYSQL_CONNECTOR_DIR}/include)
set(MYSQL_LIB_DIR ${MYSQL_CONNECTOR_DIR}/lib64)

include_directories(${MYSQL_INCLUDE_DIR})
link_directories(${MYSQL_LIB_DIR})
set(MYSQL_LIBRARIES vs14/mysqlcppconn vs14/mysqlcppconn-static)
set(MYSQL_DLL "${MYSQL_LIB_DIR}/mysqlcppconn-10-vs14.dll")

include_directories("C:/Adler_Database/src")

# Ensure the current source directory is included
include_directories(${CMAKE_SOURCE_DIR})

# Set source files - include both main.cpp and logger.cpp
set(SRCS main.cpp logger.cpp)

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
target_link_libraries(main PRIVATE ${PYTHON_LIB_PATH})
target_link_libraries(main PRIVATE pybind11::module)
target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES} ${MYSQL_LIBRARIES} ${PYTHON_LIB_PATH})

# Copy XML file after build
file(COPY ${CMAKE_SOURCE_DIR}/example.xml DESTINATION ${CMAKE_BINARY_DIR})

# Copy MySQL DLL after build
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${MYSQL_DLL}" $<TARGET_FILE_DIR:main>
)
