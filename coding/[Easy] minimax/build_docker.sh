#!/bin/bash
docker build --tag=coding_minimax .
docker run -p 1337:1337 --rm --name=coding_minimax -it coding_minimax