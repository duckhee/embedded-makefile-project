
/*
!!!Linker default script generated automatically !!!
Please note that this file and all script files included from this one can not be modified directly
If you need to use your own script please do it from Ride7 LD linker options taking this one as example
*/

SEARCH_DIR(".")
SEARCH_DIR("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj")
SEARCH_DIR("C:\Program Files\Raisonance\Ride\Lib\ARM")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\main.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\hw_config.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\led.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\debug.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\key.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\stm32f10x_it.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\zigbee_test.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\stm32f10x_usart.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\stm32f10x_gpio.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\stm32f10x_rcc.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\misc.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\stm32f10x_exti.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\stm32f10x_spi.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\startup_stm32f10x_md.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\system_stm32f10x.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\util.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\basic_rf.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\basic_rf_security.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\cc2520_mango_porting.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\hal_cc2520.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\hal_int.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\hal_rf.o")
INPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\hal_rf_security.o")
INCLUDE "D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\obj\STM32F103_128K_20K_FLASH.ld"
EXTERN( __io_putchar )
EXTERN( _write )
INPUT("STM32x_io_putchar_thumb.a")
OUTPUT("D:\WkPjt\MStory2.0\Mango-Z1.Firmware\Z1.Src006.SPI.CC2520.ID\project\RIDE\MStroy2.0.elf")
