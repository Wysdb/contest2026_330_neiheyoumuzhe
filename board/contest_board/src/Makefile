############################################################################
# vendor/openvela/boards/contest2026_330_board/src/Makefile
############################################################################

include $(BOARD_COMMON_DIR)/Make.defs

CSRCS = esp32p4_boot.c esp32p4_bringup.c esp32p4_gpio.c esp32p4_reset.c esp32p4_appinit.c

ifeq ($(CONFIG_ARCH_BUTTONS),y)
CSRCS += esp32p4_buttons.c
endif

ifeq ($(CONFIG_ESPRESSIF_EMAC),y)
CSRCS += esp32p4_ethernet.c
endif
