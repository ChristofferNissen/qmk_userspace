# Ploopy Adept Trackball

<https://ploopy.co/adept-trackball/>

## Instructions

Follow these instructions to use QMK to flash updated firmware, keymaps, etc.

1. Make any changes to firmware files first.
2. Open Windows terminal and open the QMK MSYS profile.
3. Build the firmware with:

    ```
    qmk compile -kb ploopyco/madromys/rev1_001 -km ChristofferNissen
    ```

    This sets the Ploopy up for Via, so use that for keymaps:
    <https://usevia.app>

4. Put the Ploopy into bootloader mode (see below).
5. Drag new ".uf2" file into Ploopy device folder.

All done!

## Putting the Ploopy into bootloader mode

Instructions from: <https://github.com/ploopyco/adept-trackball/wiki/Appendix-D%3A-QMK-Firmware-Programming#putting-the-ploopy-device-into-bootloader-mode>

1. Unplug it from your computer.
2. Hold down the Bottom Left button on the Adept.
3. Plug the Ploopy device into your computer.
4. The computer should recognise that a mass storage device was just plugged in. Once this is done, you should be able to drag and drop files onto the Ploopy device, as if the board was a USB drive.

And that's it. While plugged in this way, the Ploopy device will accept new firmware.

If you want to upload a new firmware file (a ".uf2" file, like "ploopy_adept_v42069" or something), just drag it into the folder, and it'll automatically install on the Ploopy device and restart itself.

## Links

- <https://github.com/ploopyco/adept-trackball/wiki/Appendix-D%3A-QMK-Firmware-Programming>
- <https://docs.qmk.fm/#/newbs_building_firmware>
- <https://docs.qmk.fm/#/newbs_flashing>
- <https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/>
