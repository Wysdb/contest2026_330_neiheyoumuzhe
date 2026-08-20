/****************************************************************************
 * board/contest_board/src/esp32p4_appinit.c
 *
 * board_app_initialize 是 openvela boardctl() 无条件要求每块板子提供的接口，
 * 这里把它对接到 Apache 官方板子代码里实际提供的 esp_bringup()。
 ****************************************************************************/

#include <nuttx/config.h>
#include <sys/types.h>

int esp_bringup(void);

int board_app_initialize(uintptr_t arg)
{
  return esp_bringup();
}
