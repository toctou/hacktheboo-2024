#!/bin/bash
docker build --tag=coding_addition .
docker run -p 1337:1337 --rm --name=coding_addition -it coding_addition