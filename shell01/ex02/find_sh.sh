#!/bin/sh

find . -name "*.sh" -type f -execdir basename -s ".sh" {} +
