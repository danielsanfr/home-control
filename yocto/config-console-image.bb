gpu_mem_increse() {
    echo "gpu_mem_512=448" > <path_to_rpi>/build/tmp/deploy/images/raspberrypi/bcm2835-bootfiles/config.txt
}

auto_login() {
    sed -i 's/1\:12345\:respawn\:\/sbin\/getty 38400 tty1/1:12345\:respawn\:\/bin\/login -f root tty1 \<\/dev\/tty1 \>\/dev\/tty1 2\>\&1/g' ${IMAGE_ROOTF
}

