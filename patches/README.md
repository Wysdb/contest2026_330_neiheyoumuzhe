# nuttx 公共仓库补丁

## 这是什么

ESP32-P4 在 openvela `nuttx` 仓库中的支持代码。这些改动位于 repo 管理的
上游公共仓库，无法随队伍仓库提交，因此以补丁形式保存在此。

- 基线提交：`dd92bcf425738734d1b8aed09c2bd4dbe3f2e438`
- 补丁规模：31 个文件，9385 行新增，4 行删除
- HAL 依赖：`ESP_HAL_3RDPARTY_VERSION = 8d0a898910084206721a0892ab093021bca1496a`
  （记录在 `arch/risc-v/src/esp32p4/Make.defs`，构建系统自动拉取，
   584MB 的 HAL 源码**不包含**在本补丁内）

## 什么时候需要用

- 执行过 `repo sync`
- 换了开发机器
- `nuttx` 目录被重置

## 怎么用

```bash
cd <openvela 根目录>/nuttx
git apply --check ../contest2026_330_neiheyoumuzhe/patches/0001-esp32p4-support-for-openvela.patch
git apply ../contest2026_330_neiheyoumuzhe/patches/0001-esp32p4-support-for-openvela.patch
```

`--check` 只检查不修改，先跑它确认无冲突。

## 补丁内容

| 文件 | 改动性质 |
|---|---|
| `arch/risc-v/Kconfig` | 新增 ESP32-P4 芯片选项 |
| `arch/risc-v/src/common/espressif/Kconfig` | if 条件 / choice / CHIP_SERIES 三处注册 P4 |
| `arch/risc-v/src/common/Make.defs` | 芯片层构建规则 |
| `arch/risc-v/src/esp32p4/` | 芯片层源码（来自 Apache NuttX） |
| `arch/risc-v/include/esp32p4/` | 芯片层头文件 |

详细排错过程见 `02_阶段2_3-7_BringUp复盘_01_目录搬迁与Kconfig三层注册.md`。

## 验证记录

在基线提交的干净副本上 `git apply --check` 通过。

副本用以下方式导出（**注意**：repo 管理的仓库无法直接 `git clone`，
其 `.git/objects` 是指向 `.repo/project-objects/` 的符号链接）：

```bash
mkdir -p /tmp/nuttx_patchtest
cd <openvela 根目录>/nuttx
git archive dd92bcf425738734d1b8aed09c2bd4dbe3f2e438 | tar -x -C /tmp/nuttx_patchtest
```
