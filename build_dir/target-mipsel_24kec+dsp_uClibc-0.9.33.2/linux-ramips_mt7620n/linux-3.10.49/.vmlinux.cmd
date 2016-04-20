cmd_vmlinux := /bin/bash scripts/link-vmlinux.sh mipsel-openwrt-linux-uclibc-ld  -m elf32ltsmip -G 0 -static -n -nostdlib --gc-sections --sort-section=name --build-id  -X
