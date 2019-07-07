#!/bin/bash
su root
if [$? -eq 0 ]
    echo "\033[0m[\033[31mError\033[0m]Switch to root user failed"
fi
#ver=
filename=objshell-current.deb
wget -N -T=30 https://github.com/CodesBuilder/Objective-Shell/archive/tags/$ver/$filename
dpkg -i $filename
rm -f $filename
exit
