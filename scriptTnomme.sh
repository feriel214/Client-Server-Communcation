#!/bin/bash
cd tube_nomme
gnome-terminal --tab -- bash -c "sleep 1s; ./server; exec bash -i"
gnome-terminal --tab -- bash -c "sleep 1s; ./client; exec bash -i"



