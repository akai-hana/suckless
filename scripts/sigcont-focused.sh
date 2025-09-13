#!/bin/sh
wid=$(xdotool getwindowfocus)
pid=$(xprop -id "$wid" _NET_WM_PID | awk -F' = ' '{print $2}')
[ -n "$pid" ] && kill -CONT "$pid"
