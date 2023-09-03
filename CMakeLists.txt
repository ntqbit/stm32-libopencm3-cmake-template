cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-none-eabi-gcc.cmake)

project(blink C)

include(cmake/stm32f1.cmake)

add_executable(blink src/blink.c)
target_link_libraries(blink stm32f1)
stm32_add_linker_script(blink PRIVATE src/stm32.ld)

# Automatically generate binary file for flashing
add_custom_command(TARGET blink POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:blink> $<TARGET_FILE:blink>.bin)
