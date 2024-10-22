#!/bin/sh
docker build --tag=que_onda .
docker run -it -p 1337:1337 --rm --name=que_onda que_onda
