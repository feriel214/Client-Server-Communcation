#!/bin/bash
cd socket_tcp
gnome-terminal -- bash -c "sleep 1s; ./tcpServer; exec bash -i"
gnome-terminal -- bash -c "sleep 1s; ./tcpClient; exec bash -i"
gnome-terminal -- bash -c "sleep 1s; ./tcpClient; exec bash -i"


