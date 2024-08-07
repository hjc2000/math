% PID 控制器类
classdef PidController
	properties
		KP
		KI
		KD
		Y
		X
	end
	
	methods
		function obj = PidController(KP, KI, KD)
			obj.KP = KP;
			obj.KI = KI;
			obj.KD = KD;
			obj.X = zeros(1,3);
			obj.Y = 0;
		end
		
		function Input(obj,X)
			obj.X(3) = obj.X(2);
			obj.X(2) = obj.X(1);
			obj.X(1) = X;
		end
		
		function y = Output(obj)
			p = obj.KP * (obj.X(1) - obj.X(2));
			i = obj.KI * obj.X(1);
			d = obj.KD * (obj.X(1) - 2 * obj.X(2) + obj.X(3));
			obj.Y = p + i + d + obj.Y;
			y = obj.Y;
		end
	end
end
