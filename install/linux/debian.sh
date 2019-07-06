su root
if [$? -eq 0 ]
    echo "\033[0m[\033[31mError\033[0m]Switch to root user failed"
fi
filename=objshell-current.tar.gz
wget -N -T=30 https://github.com/CodesBuilder/Objective-Shell/archive/$filename
dpkg -i $filename
rm -f objshell-current.tar.gz
exit
