#!/bin/sh

gcc -Wall -Wextra -Wpedantic -O2 -DDEBUG TCPSocket.c CarChargerAppl.c -o bin/car_charging_server
