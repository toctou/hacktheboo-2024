#!/bin/bash
docker build --tag=coding_replacement .
docker run -p 1337:1337 --rm --name=coding_replacement -it coding_replacement