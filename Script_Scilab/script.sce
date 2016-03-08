function M=MatRotation(theta)
    M=[cos(theta),-sin(theta);sin(theta),cos(theta)];
endfunction

function R=solverS(v,w,theta)
    M=[1-cos(theta),sin(theta);-sin(theta),cos(theta)];
    A=inv(M);
    R=A*[v;w];
endfunction
