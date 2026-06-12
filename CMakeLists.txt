cmake_minimum_required(VERSION 3.16)
project(AgentePETE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.11.0/mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

include_directories(include)

add_executable(AgentePETE
    src/main.cpp
    src/MainWindow.cpp
    src/ChatController.cpp
    src/Prompt.cpp
    src/Message.cpp
    include/MainWindow.h
    include/ChatController.h
    include/Prompt.h
    include/Message.h
    src/OllamaProvider.cpp
    include/OllamaProvider.h
)

target_link_libraries(AgentePETE
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network
)
