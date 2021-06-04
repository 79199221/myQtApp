cmake_minimum_required(VERSION 3.0)
project(myApp)

# 指定c++标准的版本
set(CMAKE_CXX_STANDARD 17)

#link_libraries(sqlite3)

# Find includes in corresponding build directories
# 自动添加CMAKE_CURRENT_BINARY_DIR和CMAKE_CURRENT_SOURCE_DIR
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct Cmake to run moc automatically when needed
# 打开Qt的MOC功能和UIC文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
# Set CMAKE_PREFIX_PATH to find Qt5 Package 设置前缀路径以寻找Qt5的库
set(CMAKE_PREFIX_PATH D:\\Qt\\Qt5.14.2\\5.14.2\\mingw73_64\\lib\\cmake)
set(INC_DIR D:\\Qt\\Qt5.14.2\\5.14.2\\mingw73_64\\include)
set(LINK_DIR D:\\Qt\\Qt5.14.2\\5.14.2\\mingw73_64\\lib)
include_directories(${INC_DIR} )
link_directories(${LINK_DIR})
# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin) # 将输出重定向到bin子目录
set(SOURCE_FILES
        main.cpp
        src/window/main/MainWindow.h src/window/main/MainWindow.cpp
        src/window/login/LoginWindow.h src/window/login/LoginWindow.cpp
        src/common/menu_bar.h src/common/menu_bar.cpp
        src/common/status_bar.h src/common/status_bar.cpp
        src/db/db.h src/db/db.cpp
        src/db/user.h src/db/user.cpp
        src/ui/login_window.ui src/ui/login_window.h src/ui/login_window.cpp
        src/i18n/zh_CN.ts
        )
add_executable(myApp ${SOURCE_FILES})
# Use the Widgets module from Qt 5.
target_link_libraries(myApp Qt5::Widgets Qt5::Gui)