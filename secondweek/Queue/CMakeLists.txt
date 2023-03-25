# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.5)
# 项目信息
project(Queue)
# 设置输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Release)
#添加头文件路径
include_directories(${PROJECT_SOURCE_DIR}/Headers)
#查找Sources文件夹下源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/Sources DIR_SRCS)
#编译
add_executable(Queue ${DIR_SRCS})