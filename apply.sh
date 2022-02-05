#!/bin/sh

git switch Learn
git pull origin Live

git switch Retake
git pull origin Live

git switch Live
git pull origin Live

echo "Completed!"
