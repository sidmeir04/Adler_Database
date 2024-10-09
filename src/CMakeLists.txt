cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(wx_cmake_template_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# hack for buggy CMake's FindwxWidgets script
if(DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED COMPONENTS core base xml)

# MySQL Connector C++: Specify the MySQL include and library directories
set(MYSQL_CONNECTOR_DIR "C:/libraries/MySQL/MySQL_Connector_C++_9.0")
set(MYSQL_INCLUDE_DIR ${MYSQL_CONNECTOR_DIR}/include)
set(MYSQL_LIB_DIR ${MYSQL_CONNECTOR_DIR}/lib64)

include_directories(${MYSQL_INCLUDE_DIR})
link_directories(${MYSQL_LIB_DIR})
set(MYSQL_LIBRARIES vs14/mysqlcppconn vs14/mysqlcppconn-static)
set(MYSQL_DLL "${MYSQL_LIB_DIR}/mysqlcppconn-10-vs14.dll")


include_directories("C:/Adler_Database/src")

set(SRCS sql_connector.cpp main.cpp)

include(${wxWidgets_USE_FILE})

if(APPLE)
    # create bundle on apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(main WIN32 ${SRCS} main.exe.manifest)
endif()

target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES} ${MYSQL_LIBRARIES})

add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${MYSQL_DLL}" $<TARGET_FILE_DIR:main>
)