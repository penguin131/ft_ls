cmake_minimum_required(VERSION 3.14)
project(ft_ls C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
include_directories(libft)
include_directories(src)

add_executable(ft_ls
        inc/ft_ls.h
        src/main.c src/handle_error.c src/files.c src/print_files.c)

target_link_libraries(ft_ls /Users/smight/Desktop/ft_ls/libft/libft.a)
target_link_libraries(ft_ls /Users/smight/Desktop/ft_ls/libft/libftprintf.a)