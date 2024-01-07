function df = full_diff(f)
    fsym = symvar(f);
    df = sym(0);
    for s = fsym
        df = df + diff(f,s) * sym(['d',char(s)]);
    end

    % df=expand(df);
    % for s = fsym
    %     df=subs(df,sym(['d',char(s)])^2,0);
    % end

    df=simplify(df);
end