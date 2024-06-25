function var=StepFormZeroInRange(LeftLimit,RightLimit,Step)
    var=0:-Step:LeftLimit;
    var=flip(var);
    var=[var(1:end-1),[0:Step:RightLimit]];
    if(isempty(var))
        var=0;
    end
end