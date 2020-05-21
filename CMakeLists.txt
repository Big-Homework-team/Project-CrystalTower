cmake_minimum_required(VERSION 2.8)
project(Project_CrystalTower)

# 设置编译模式
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=GBK -finput-charset=UTF-8") # 解决编码问题
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

add_executable(Project_CrystalTower ${DIR_SRCS})
target_link_libraries(Project_CrystalTower -lgraphics64 -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm -lgdiplus)