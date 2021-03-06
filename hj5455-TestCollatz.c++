// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}


// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(446945, 446944);
    ASSERT_EQ(139, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(300, 300);
    ASSERT_EQ(17, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1000, 5000);
    ASSERT_EQ(238, v);}

// Test My functions

TEST(CollatzFixture, calc) {
    const int v = collatz_calc(10);
    ASSERT_EQ(7, v);}


TEST(CollatzFixture, calc_1) {
    const int v = collatz_calc(999);
    ASSERT_EQ(50, v);}

TEST(CollatzFixture, calc_2) {
    const int v = collatz_calc(5000);
    ASSERT_EQ(29, v);}


TEST(CollatzFixture, calc_map_1) {
    const int v = collatz_calc_map(10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, calc_map_2) {
    const int v = collatz_calc_map(999);
    ASSERT_EQ(50, v);}

TEST(CollatzFixture, calc_map_3) {
    const int v = collatz_calc_map(5000);
    ASSERT_EQ(29, v);}









// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
/*
% g++-4.8 -pedantic -std=c++11 -Wall -fprofile-arcs -ftest-coverage Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -pthread
% valgrind ./TestCollatz                                           >  TestCollatz.tmp 2>&1
% gcov-4.8 -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"     >> TestCollatz.tmp
% gcov-4.8 -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'" >> TestCollatz.tmp
*/
