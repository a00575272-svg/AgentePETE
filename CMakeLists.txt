cmake_minimum_required(VERSION 3.16)
project(AgentePETE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

include_directories(include)

add_executable(AgentePETE
    src/main.cpp
    src/MainWindow.cpp
    src/ChatController.cpp
    include/MainWindow.h
    include/ChatController.h
)

target_link_libraries(AgentePETE
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)
