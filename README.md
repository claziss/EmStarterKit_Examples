EmStarterKit_Examples
=====================

Code examples for ARCv2EM starter kit.

Memory map
=========

The EM starter kit architecture has two configurations. The memory layouts are as follows:

For EM4:
0x0000000  -  0x0080000  ICCM (128K)
0x0800000  -  0x0F00000  DCCM(128K)

For EM6:
0x0000000  -  0x0008000  ICCM (32K)
0x1000000  -  0x1800000  DDR3 (128MB)

The related linker memory files are found in Configuration folder.
