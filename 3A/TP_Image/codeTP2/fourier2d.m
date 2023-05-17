function [] = fourier2d(img,fe)

dim = size(img);

f = abs(fftshift( fft2(img) ) );
n = dim(1)/2;
m = dim(2)/2;

figure();
surf(fe*(-m:m-1)/dim(1),(fe*(-n:n-1))/dim(2),sqrt(f));
title ({"Spectre - 1"});
xlabel ("Fx");
ylabel ("Fy");
zlabel ("Amplitude");

figure();
contourf(fe*(-n:n-1)/dim(1),fe*(-m:m-1)/dim(2),log(5*f'+1));
title ({"Spectre - 2"});
xlabel ("Fy");
ylabel ("Fx");
endfunction

