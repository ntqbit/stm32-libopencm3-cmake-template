add_library(stm32f1 STATIC IMPORTED)

set_property(TARGET stm32f1 PROPERTY INTERFACE_INCLUDE_DIRECTORIES "/usr/arm-none-eabi/include")
set_property(TARGET stm32f1 PROPERTY IMPORTED_LOCATION "/usr/arm-none-eabi/lib/libopencm3_stm32f1.a")

target_compile_definitions(stm32f1 INTERFACE -DSTM32F1)

target_link_options(stm32f1 INTERFACE
  --static
  -nostartfiles
  -fno-common
  -msoft-float
  -mcpu=cortex-m3
  -mthumb
  -mfix-cortex-m3-ldrd
)
