function [img] = atom(n,m,fx,fy)

img=[];
e1 = exp(i*2*pi*fx*(0:m-1));
e2 = exp(i*2*pi*fy*(0:n-1));
img = real(e2'*e1);

endfunction
