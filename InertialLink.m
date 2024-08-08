classdef InertialLink < handle
    properties
        T
        T1
        Y
    end

    methods
        function obj=InertialLink(T,T1)
            obj.T=T;
            obj.T1=T1;
            obj.Y=0;
        end

        function y = Input(obj,x)
			y=(obj.T1 / (obj.T1+obj.T)) * obj.Y + (obj.T / (obj.T1+obj.T)) * x;
        end
    end
end