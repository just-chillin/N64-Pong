## Overview
It's pong for the Nintendo 64!

## Why I made this
A Youtube rabbit hole led me into finding out about https://github.com/DragonMinded/libdragon. Since I am interested in old hardware and video games I decided to try writing something basic with it.

## How to Compile
Simply run `./run.sh`. A build container will be configured, a rom will be compiled, and ares will automatically start with the compiled rom.

You can also copy the build output to an everdrive64 and play it on real hardware.

### Dependencies
- https://github.com/anacierdem/libdragon-docker. This sets up the build container and allows you to execute make commands in it.
- https://docs.docker.com/get-docker/. Required to run the build container.
- https://ares-emu.net/. Ares is an accurate n64 emulator. Make sure it's installed to `/Applications` because that's how it's configured on my machine. You CANNOT use mupen64 or any other emulator because they rely on HLE, which is incompatible with libdragon.

Easier instructions TODO
