#rm -rf out
mkdir -p out


#ARCH
export ARCH=arm64

#host and user
export KBUILD_BUILD_USER="DhirajMS"
export KBUILD_BUILD_HOST="OK"
export CROSS_COMPILE=$PWD/tc/bin/aarch64-linux-android-

make O=out msmcortex_defconfig

#CompileNow
make O=out -j128
