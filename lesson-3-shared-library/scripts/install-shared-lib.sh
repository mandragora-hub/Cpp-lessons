#!/bin/bash

su
install -m 0755 ./shared/libSimpleEncoder.so.1.1.1 /usr/local/lib
ln -sf /usr/local/lib/libSimpleEncoder.1.1.1 /usr/local/lib/libSimpleEncoder.so
ldconfig # update dynamic linker cache ! very important
exit