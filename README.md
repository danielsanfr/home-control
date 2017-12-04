# Simple Home Control

This is a project for the discipline of Topics in Operating Systems, made by me, during my graduation at [UFAL](http://www.ufal.edu.br).

**Professor:** [Rodrigo Peixoto](https://www.github.com/rodrigopex)

Below I will briefly cite some information that was used to achieve the minimum required.

## Things to remember

The **yocto** folder contains some files to help configure the linux image build.

First you need to compile the QtUPnP lib with the **arm compiler**. This can be done as described below for the main application.
The **yocto/homecontrol** folder was copied to the **rpi/meta-rpi /recipes-qt** folder.
Then the **homecontrol** was added in the **QML_APPS** session of the **rpi/meta-rpi/images/qt5-image.bb** file.

To customize the splash screen was used: [psplash](http://git.yoctoproject.org/cgit/cgit.cgi/psplash).
For this the command was executed: `./make-image-header.sh <image> POKY`.
And the output file has been placed in place of the following files: **meta-poky/recipes-core/psplash/files/psplash-poky-img.h** and **meta/recipes-core/psplash/files/psplash-poky-img.h**

To remove the raspberry logo, you need to edit the file **/boot/cmdline.txt**, adding **logo.nologo**. To more info, search for _raspberry pi cmdline.txt_ on google.

## References

* http://www.jumpnowtek.com/rpi/Raspberry-Pi-Systems-with-Yocto.html
* https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md
* https://www.argon40.com/resources/how-to-enable-your-raspberry-pi-3-wifi-via-terminal/
* https://raspimint.blogspot.com.br/2016/11/wifi-on-raspberrypi-remotely.html
* https://www.raspberrypi.org/forums/viewtopic.php?t=39690
* http://opentechguides.com/how-to/article/raspberry-pi/5/raspberry-pi-auto-start.html
* https://raspberrypi.stackexchange.com/questions/59310/remove-boot-messages-all-text-in-jessie
