#!/bin/bash

# decimal to binary
./convert -inD -outB -8 12
./convert -inD -outB -8 127
./convert -inD -outB -8 128
./convert -inD -outB -8 255
./convert -inD -outB -8 300
./convert -inD -outB -16 300
./convert -inD -outB -32 300
./convert -inD -outB -16 32767
./convert -inD -outB -16 32768
./convert -inD -outB -64 300

# decimal to hex
./convert -inD -outH -8 12
./convert -inD -outH -8 127
./convert -inD -outH -8 128
./convert -inD -outH -8 255
./convert -inD -outH -8 300
./convert -inD -outH -16 300
./convert -inD -outH -32 300
./convert -inD -outH -16 32767
./convert -inD -outH -16 32768
./convert -inD -outH -64 300

# binary to decimal
./convert -inB -outD -8 101010
./convert -inB -outD -8 111100001
./convert -inB -outD -16 111100001
./convert -inB -outD -16 111100001111
./convert -inB -outD -16 1111000011110000
./convert -inB -outD -32 1111000011110011
./convert -inB -outD -32 111100001111000011110000
./convert -inB -outD -32 11111111111111111111111111111111

# binary to hex
./convert -inB -outH -8 101010
./convert -inB -outH -8 111100001
./convert -inB -outH -16 111100001
./convert -inB -outH -16 111100001111
./convert -inB -outH -16 1111000011110000
./convert -inB -outH -32 1111000011110011
./convert -inB -outH -32 111100001111000011110000
./convert -inB -outH -32 11111111111111111111111111111111

# hex to decimal
./convert -inH -outD -8 2a
./convert -inH -outD -8 1e1
./convert -inH -outD -16 1e1
./convert -inH -outD -16 f0f
./convert -inH -outD -16 f0f0
./convert -inH -outD -32 f0f3
./convert -inH -outD -32 f0f0f0
./convert -inH -outD -64 ffffffff

# hex to binary
./convert -inH -outB -8 1234567890abcdef
./convert -inH -outB -64 1234567890abcdef

# same base, just formatting
./convert -inH -outH -8 1234567890abcdef
./convert -inH -outH -64 1234567890abcdef
./convert -inD -outD -8 1234567890
./convert -inD -outD -16 1234567890
./convert -inD -outD -64 1234567890
./convert -inB -outB -8 111110000
./convert -inB -outB -32 111110000

# error cases
./convert -abc -outD -8 101
./convert -inB -defg -8 101
./convert -inB -outD -9 101
./convert -inB -outD -8 121
./convert -inD -outB -8 1a1
./convert -inH -outB -8 12g
./convert -inD -outB -8