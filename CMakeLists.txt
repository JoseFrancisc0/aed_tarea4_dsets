cmake_minimum_required(VERSION 3.0.0)
project(TAREA_SEMANA_4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(TAREA_SEMANA_4 main.cpp disjoint_set.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
