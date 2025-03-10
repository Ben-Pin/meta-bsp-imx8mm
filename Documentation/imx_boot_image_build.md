# Building Boot Firmware for CompuLab's i.MX8M Mini products

Supported machines:

* `mcm-imxi8-mini`
* `ucm-imxi8-mini`
* `iot-gate-imx8`

Define a `MACHINE` environment variable for the target product:

|Machine|Command Line|
|---|---|
|mcm-imx8m-mini|export MACHINE=mcm-imx8m-mini
|ucm-imx8m-mini|export MACHINE=ucm-imx8m-mini
|iot-gate-imx8|export MACHINE=iot-gate-imx8

Define the following environment variables:

|Description|Command Line|
|---|---|
|NXP u-boot release|export NXP_UBOOT_RELEASE=lf-5.10.35-2.0.0|
|NXP ATF release|export NXP_ATF_RELEASE=lf-5.10.35-2.0.0|
|NXP mkimage release|export NXP_MKIMAGE_RELEASE=lf-5.10.35-2.0.0|
|NXP firmware name|export NXP_FIRMWARE=firmware-imx-8.12.bin|
|CompuLab branch name|export CPL_BRANCH=rel_imx_5.10.35_2.0.0-stable|


## Prerequisites
It is up to developer to setup arm64 build environment:
* Download and install the [GNU tool chain](https://github.com/compulab-yokneam/meta-bsp-imx8mm/blob/rel_imx_5.10.35_2.0.0-experiment/Documentation/toolchain.md)

* Create a folder to organize the files:
<pre>
mkdir imx8mm
cd imx8mm
export SRC_ROOT=$(pwd)
</pre>

* Download CompuLab BSP
<pre>
git clone -b ${CPL_BRANCH} https://github.com/compulab-yokneam/meta-bsp-imx8mm.git
export LAYER_DIR=$(pwd)/meta-bsp-imx8mm
</pre>

## Mkimage setup
* Download the mkimage:
<pre>
git clone https://github.com/nxp-imx/imx-mkimage.git
git -C imx-mkimage checkout ${NXP_MKIMAGE_RELEASE}
</pre>

## Arm Trusted Firmware (ATF) setup
* Download the ATF:
<pre>
git clone https://github.com/nxp-imx/imx-atf.git
git -C imx-atf checkout ${NXP_ATF_RELEASE}
git -C imx-atf am ${LAYER_DIR}/recipes-bsp/imx-atf/compulab/imx8mm/*.patch
</pre>
* Make bl31.bin
<pre>
make -C imx-atf PLAT=imx8mm bl31
cp -v imx-atf/build/imx8mm/release/bl31.bin ${SRC_ROOT}/imx-mkimage/iMX8M/
</pre>

## Firmware iMX setup
* Download the firmware-imx file:
<pre>
wget http://www.freescale.com/lgfiles/NMG/MAD/YOCTO/${NXP_FIRMWARE}
bash -x ${NXP_FIRMWARE} --auto-accept
cp -v $(find firmware* | awk '/train|hdmi_imx8|dp_imx8/' ORS=" ") ${SRC_ROOT}/imx-mkimage/iMX8M/
</pre>

## U-Boot
* Download the U-Boot source and apply CompuLab BSP patches:
<pre>
git clone https://github.com/nxp-imx/uboot-imx.git
git -C uboot-imx checkout ${NXP_UBOOT_RELEASE}
git -C uboot-imx am ${LAYER_DIR}/recipes-bsp/u-boot/compulab/imx8mm/*.patch
</pre>

* Compile U-Boot:
<pre>
make -C uboot-imx -f defconfig.mk
make -C uboot-imx
</pre>

* Copy files to the mkimage directory:
<pre>
cp -v $(find uboot-imx | awk -v v=${MACHINE} '(/u-boot-spl.bin$|u-boot.bin$|u-boot-nodtb.bin$|tools\/mkimage$/)||($0~v".dtb$")' ORS=" ") ${SRC_ROOT}/imx-mkimage/iMX8M/
</pre>

<!---
## OP-TEE Setup
Download the OP-TEE from:
<pre>
git clone https://github.com/nxp-imx/imx-optee-os.git
git -C imx-optee-os checkout ${NXP_RELEASE} -b ${CPL_BRANCH}
git -C imx-atf am ${LAYER_DIR}/recipes-security/optee-imx/compulab/imx8mm/*.patch
</pre>

* Set environment variables:
<pre>
export ARCH=arm
export CROSS_COMPILE=/usr/bin/arm-linux-gnu-
export CROSS_COMPILE64=/usr/bin/arm-linux-gnu-
</pre>

* Make tee.bin
<pre>
cd imx-optee-os
./scripts/imx_build.sh mx8mmevk
cp -v build.mx8mmevk/core/tee.bin ${SRC_ROOT}/imx-mkimage/iMX8M/
</pre>
-->

## Compiling the **flash.bin** imx-boot image:
* Unset these variables:
<pre>
unset ARCH CROSS_COMPILE
</pre>
* Issue:
<pre>
cd ${SRC_ROOT}/imx-mkimage/iMX8M
sed "s/\(^dtbs = \).*/\1${MACHINE}.dtb/;s/\(mkimage\)_uboot/\1/" soc.mak > Makefile
make clean
make flash_evk SOC=iMX8MM
</pre>

## Flashing
`dd if=flash.bin of=/dev/<your device> bs=1K seek=33 status=progress`
