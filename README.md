# STM32F0 example project

Minimal example project for STM32F0 and arm-none-eabi-gcc

## Sources and dependencies

- AUR package [stm32f0-headers-git](https://aur.archlinux.org/packages/stm32f0-headers-git)
- Makefile and main.c from [WRansohoff/STM32_quickstart](https://github.com/WRansohoff/STM32_quickstart/tree/d8c2a2328ed44e3319bcd777cfe0c3b95022fac9)
- From [STMicroelectronics/STM32CubeF0](https://github.com/STMicroelectronics/STM32CubeF0/tree/v1.11.3)
    - [STM32F051x8.ld](https://github.com/STMicroelectronics/STM32CubeF0/blob/v1.11.3/Projects/STM32F0308-Discovery/Examples/UART/UART_TwoBoards_ComDMA/SW4STM32/STM32F0308-Discovery/STM32F030R8Tx_FLASH.ld)
    - [startup_stm32f051x8.s](https://github.com/STMicroelectronics/STM32CubeF0/blob/v1.11.3/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f051x8.s)
    - [system_stm32f0xx.c](https://github.com/STMicroelectronics/STM32CubeF0/blob/v1.11.3/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c)
- From [szczys/stm32f0-discovery-basic-template](https://github.com/szczys/stm32f0-discovery-basic-template/tree/d29476db3aa759bbad4cb432c883b14d99ac56da)
    - [stm32f0-openocd.cfg](https://github.com/szczys/stm32f0-discovery-basic-template/blob/d29476db3aa759bbad4cb432c883b14d99ac56da/extra/stm32f0-openocd.cfg)
