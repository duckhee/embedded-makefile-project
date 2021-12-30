###########################################################
# GCC template makefile
###########################################################

ESP_SOURCES = 
ESP_SOURCES += esp8266.c
ESP_SOURCES += esp8266_tcp.c

EXTRAINCDIRS += $(TOP)/Library/module/esp8266/Inc

C_SOURCES += $(ESP_SOURCES)