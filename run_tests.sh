#!/bin/bash

bison c2f3.y
gcc -Wall c2f3.tab.c -o c2

blue='\033[0;34m'
green='\033[0;32m'
NC='\033[0m'
bold=$(tput bold)
normal=$(tput sgr0)

rm -rf test_results
rm -rf test_output
mkdir test_results
mkdir test_output
echo ${green}Results directory cleaned ${NC}
echo ${green}${bold}No output after a test means success ${normal}${NC}
echo ""
echo ${green}Starting basic tests...

for i in $( ls test_basicos ); do
    echo ${blue}Translating basic tests: $i ${NC}
    touch test_results/$i.forth
    cat test_basicos/$i | ./c2 > test_results/$i.forth

    echo ${blue}Executing basic tests: $i ${NC}
    touch test_output/$i.forth
    cat test_basicos/$i | ./c2 | gforth > test_output/$i.out
done

echo ${green}Basic tests finished.
echo ""
echo ${green}Starting advanced tests...

for i in $( ls test_avanzados ); do
    echo ${blue}Translating advanced tests: $i ${NC}
    touch test_results/$i.forth
    cat test_avanzados/$i | ./c2 > test_results/$i.forth

    echo ${blue}Executing advanced tests: $i ${NC}
    touch test_output/$i.forth
    cat test_avanzados/$i | ./c2 | gforth > test_output/$i.out
done

echo ${green}Advanced tests finished.
echo ""
echo ${green}Starting custom tests...

echo ${blue}Translating custom tests: test.c ${NC}
cat test.c | ./c2 > test_results/test.forth

echo ${blue}Executing advanced tests: test.c ${NC}
cat test.c | ./c2 | gforth > test_output/test.out

echo ${green}Custom tests finished.
