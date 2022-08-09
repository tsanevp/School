#!/bin/bash

cd ~/Course_Resources/
git pull

echo -n "Please enter the folder to copy"
read str
DIR="~/Tsanevp_CS5008SPRING2022/$str/"
if [ ! -d "$DIR" ] && [ "$str" == "new folder" ]
then    
    cp -R [ "$str" ] ~/Tsanevp_CS5008SPRING2022/
else
    echo "Pull is up-to-date or does not match current repo and thus was not copied"
fi
