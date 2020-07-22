# JZJCoreSoftware

Contains software to run on JZJCoreX cores

## Memory Map

Note: addresses are inclusive, bounds not specified are not addressed to anything, and execution starts at 0x00000000

| Bytewise Address (whole word) | Physical Word-wise Address | Function |
|:------------------------------|:---------------------------|:---------|
|0x00000000 to 0x00000003|0x00000000|RAM Start|
|0x0000FFFC to 0x0000FFFF|0x00003fff|Ram End|
|0xFFFFFFE0 to 0xFFFFFFE3|0x3FFFFFF8|Memory Mapped IO Registers Start|
|0xFFFFFFFC to 0xFFFFFFFF|0x3FFFFFFF|Memory Mapped IO Registers End|
