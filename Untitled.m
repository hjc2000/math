clear;
clc;
close all;

syms x t
equ = t==x-1/x;
solve_x=solve(equ,x);
solve_x=simplify(solve_x)