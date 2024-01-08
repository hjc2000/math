function re=MyEval(str)
	syms x
	re=solve(['x==',str]);
end