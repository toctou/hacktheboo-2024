#!/bin/bash
docker build --tag=coding_reversal .
docker run -p 1337:1337 --rm --name=coding_reversal -it coding_reversal