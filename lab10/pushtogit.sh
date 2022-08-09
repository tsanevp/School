!/bin/bash

# Shell script to push current commits in current directory

echo "Running git add/commit/push from" $PWD

cd $PWD

git add -A .

echo "Enter commit message: "

git commit -m "$commitMessage"

git push

echo "Push is complete"
