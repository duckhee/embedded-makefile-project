
/*
!!!Linker default script generated automatically !!!
Please note that this file and all script files included from this one can not be modified directly
If you need to use your own script please do it from Ride7 LD linker options taking this one as example
*/

SEARCH_DIR(".")
SEARCH_DIR("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj")
SEARCH_DIR("C:\Program Files\Raisonance\Ride\Lib\ARM")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\ymodem.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\common.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\download.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\main.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32_eval.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_it.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_rcc.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_wwdg.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\misc.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_exti.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_flash.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_gpio.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\stm32f10x_usart.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\core_cm3.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\system_stm32f10x.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\obj\startup_stm32f10x_md.o")
INCLUDE "D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\STM32F103_128K_20K_FLASH.ld"
EXTERN( __io_putchar )
EXTERN( _write )
INPUT("STM32x_io_putchar_thumb.a")
OUTPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src005.AN2557.IAP.BootLoader\project\RIDE\MStroy2.0.elf")
