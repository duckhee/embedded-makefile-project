
/*
!!!Linker default script generated automatically !!!
Please note that this file and all script files included from this one can not be modified directly
If you need to use your own script please do it from Ride7 LD linker options taking this one as example
*/

SEARCH_DIR(".")
SEARCH_DIR("D:\WkPjt\MStory2.0\Mango-M32.Firmware\M32.Src005.LedAllOnOff\project\RIDE\obj")
SEARCH_DIR("C:\Program Files\Raisonance\Ride\Lib\ARM")
INPUT("D:\WkPjt\MStory2.0\Mango-M32.Firmware\M32.Src005.LedAllOnOff\project\RIDE\obj\main.o")
INPUT("D:\WkPjt\MStory2.0\Mango-M32.Firmware\M32.Src005.LedAllOnOff\project\RIDE\obj\startup_stm32f10x_md.o")
INCLUDE "D:\WkPjt\MStory2.0\Mango-M32.Firmware\M32.Src005.LedAllOnOff\project\RIDE\obj\STM32F103_128K_20K_FLASH.ld"
OUTPUT("D:\WkPjt\MStory2.0\Mango-M32.Firmware\M32.Src005.LedAllOnOff\project\RIDE\MStroy2.0.elf")
