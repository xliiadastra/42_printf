cmake_minimum_required(VERSION 3.21)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf
        ft_write_address.c
        ft_write_string.c
        ft_write_character.c
        ft_write_unsigned.c
        ft_write_decimal.c
        ft_write_upper_hex.c
        ft_format_specifier.c
        ft_write_integer.c
        pf_strlen.c
        ft_printf.c
        ft_write_lower_hex.c
        ft_printf.h
        ft_write_percent.c
        main.c)
