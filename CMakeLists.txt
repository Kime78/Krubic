cmake_minimum_required(VERSION 3.11.0)

project(Krubic C)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)


add_executable(Krubic main.c glad.c shaders.c)

include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(Krubic ${OPENGL_LIBRARIES} glfw glm ${CMAKE_DL_LIBS})
