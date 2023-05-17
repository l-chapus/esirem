function affiche_image(img)
% Fonction d affichage d'une image composee de 256 NG

figure();
imshow(img);
%xset("colormap", graycolormap(256));
a=gca(); % get the handle of the current axes
%a.axes_visible="off";
endfunction
