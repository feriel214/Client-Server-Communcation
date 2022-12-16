#!/bin/bash
cd socket_udp
gnome-terminal  -- bash -c "sleep 1s; ./udpServer; exec bash -i"
gnome-terminal  -- bash -c "sleep 1s; ./udpClient; exec bash -i"
gnome-terminal -- bash -c "sleep 1s; ./udpClient; exec bash -i"


