#!/bin/bash
docker build --tag=coding_oddly_even .
docker run -p 1337:1337 --rm --name=coding_oddly_even -it coding_oddly_even