cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-none-eabi-gcc.cmake)

project(firmware C)

include(cmake/stm32f1.cmake)

add_executable(firmware src/main.c)
target_link_libraries(firmware stm32f1)
stm32_add_linker_script(firmware PRIVATE src/stm32.ld)

# Automatically generate binary file for flashing
add_custom_command(TARGET firmware POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:firmware> $<TARGET_FILE:firmware>.bin)
