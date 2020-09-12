# JZJCoreSoftware

Contains software to run on JZJCoreX cores

## Memory Map

Note: addresses are inclusive, bounds not specified are not addressed to anything, and execution starts at 0x00000000

| Byte-wise Address (whole word) | Backend Word-wise Address | Function |
|:------------------------------|:---------------------------|:---------|
|0x00000000 to 0x00000003|0x00000000|RAM Start|
|0x00003FFC to 0x00003FFF|0x00000FFF|RAM End (Default for 12 bit RAM_A_WIDTH)|
|0xFFFFFFE0 to 0xFFFFFFE3|0x3FFFFFF8|Memory Mapped IO Registers Start|
|0xFFFFFFFC to 0xFFFFFFFF|0x3FFFFFFF|Memory Mapped IO Registers End|
