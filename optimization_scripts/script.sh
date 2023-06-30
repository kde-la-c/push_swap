#!/bin/bash

NUMBERS="9 2 7 6 5"


RET=$(./push_swap 3 $NUMBERS | wc -l)
echo $RET > output