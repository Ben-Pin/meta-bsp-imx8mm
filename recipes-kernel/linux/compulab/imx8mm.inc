SRC_URI_append = " \
	file://0001-imx8m-mini-add-basic-support.patch \
	file://0002-dts-Fix-usdhc1-properties.patch \
	file://0003-defconfig-Delete-some-unnecessary-drivers.patch \
	file://0004-ucm-imx8m-mini-dts-remove-phy-supply.patch \
	file://0005-ucm-imx8m-mini-dts-Enable-onboard-LED.patch \
	file://0006-ucm-imx8m-mini-dts-Enable-onboard-EEPROM.patch \
	file://0007-dts-Fix-pmic-interrupt-configuration.patch \
	file://0008-defconfig-Enable-regualtor.patch \
	file://0009-eeprom-Add-w25q16-support.patch \
	file://0010-ucm-imx8m-mini-defconf-dt-Migrate-to-kernel-5.4.24.patch \
	file://0011-ucm-imx8m-mini-dts-Fix-PMIC-node.patch \
	file://0012-ucm-imx8m-mini-dts-Cleaning.patch \
	file://0013-ucm-imx8m-mini-dts-Update-PCIe-node.patch \
	file://0014-rtc-abx80x-Enable-SQW-output.patch \
	file://0015-rtc-abx80x-Enable-XT-digital-calibration.patch \
	file://0016-rtc-abx80x-Calibrate-RTC.patch \
	file://0017-ucm-dts-Fix-no-1-8-v-for-mmc2.patch \
	file://0018-dts-Fix-ldo1-ldo2-voltage.patch \
	file://0019-ucm-imx8m-mini-dts-Fix-rtc-enumeration-order.patch \
	file://0020-rtc-abx80x-Improve-sqw-generation.patch \
	file://0021-rtc-abx80x-Improve-xt_calibration.patch \
	file://0022-rtc-abx80x-Add-sqw-binding-doc.patch \
	file://0023-rtc-abx80x-Add-xt_calibration-binding-doc.patch \
	file://0024-arm64-dts-imx8mm-specify-dma-ranges.patch \
	file://0025-defconfig-Disable-fw-user-loader-helper.patch \
	file://0026-ucm-imx8m-mini-dts-Fix-usdhc1-node-descriptor.patch \
	file://0027-rtc-abx80x-Disable-bus-when-powered-from-battery.patch \
	file://0028-Remove-unnecessary-stuff.patch \
	file://0029-ucm-imx8m-mini-dts-Enable-brcm-bcm4330-bt.patch \
	file://0030-ucm-imx8m-mini-config-Set-CONFIG_IMX_SDMA-m-for-brcm.patch \
	file://0031-ucm-imx8m-mini-config-Add-brcm-firmware-to-kernel-bu.patch \
	file://0032-ucm-dts-Enable-bcm4329-fmac-WiFi.patch \
	file://0033-ucm-dts-Fix-voltage-on-USDHC1.patch \
	file://0034-ucm-defconfig-Clean-regulators.patch \
	file://0035-ucm-defconfig-Enable-rfkill.patch \
	file://0036-ucm-Enable-display-kd050hdfia020-with-touchscreen.patch \
	file://0037-ov5640_mipi_v2-gpio_set_value_cansleep.patch \
	file://0038-dts-Enable-ov5640-camera-and-VPU.patch \
	file://0039-ucm-Enable-wm8731-audiocodec.patch \
	file://0040-ucm-imx8m-mini-Fix-iwlwifi.patch \
	file://0041-drm-Panel-fix.patch \
	file://0042-snd-Fix-resource-management.patch \
	file://0043-config-Fix-build-time-warnings.patch \
	file://0044-defconfig-Break-down-to-common-and-specific-parts.patch \
	file://0045-dtb-Add-mcm-device-trees.patch \
	file://0046-defconfig-Fix-PCIe-and-mPCIE_USB.patch \
	file://0047-defconfig-Fix-mipi-csi-camera.patch \
	file://0048-dts-ucm-imx8m-mini-Add-_thermal_-dts.patch \
	file://0049-mcm-dts-Calibrate-RTC.patch \
	file://0050-mcm-dts-Reorder-DTS.patch \
	file://0051-mcm-imx8m-mini-dts-Fix-rtc-enumeration-order.patch \
	file://0052-mcm-imx8m-mini-defconfig-Enable-CAN-mcp251x.patch \
	file://0053-dts-phy-Eliminate-excessive-reset.patch \
	file://0054-LOCALVERSION-2.2.1.patch \
	file://0055-dts-defconfig-Fix-cpufreq-sysfs-attr-disappearance.patch \
	file://0056-dts-Enable-rpmsg.patch \
"

