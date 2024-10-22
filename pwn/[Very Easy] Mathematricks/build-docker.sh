#!/bin/sh
docker build --tag=mathematricks .
docker run -it -p 1337:1337 --rm --name=mathematricks mathematricks
