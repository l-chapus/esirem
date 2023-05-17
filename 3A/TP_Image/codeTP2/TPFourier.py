import numpy as np

from matplotlib import pyplot as plt
import cv2 as cv
from mpl_toolkits import mplot3d

def affiche_image(img):
    plt.figure()
    plt.imshow(img,cmap="gray")
    plt.colorbar()

def  atom(n,m,fx,fy):
    img=np.zeros((n, m))
    x = np.array(np.arange(0,m))
    y = np.arange(0,n)
    e1 = np.exp(1j*2*np.pi*fx*x)
    e2 = np.exp(1j*2*np.pi*fy*y)
    for i in range(n):
        for j in range(m):
            img[i,j] = np.real(e2[i]*np.conjugate(e1[j]))
    return img

def fourier2d(img,fe):
    #récupère les dimensions de l'image
    [height, width] = img.shape


    f = np.abs(np.fft.fftshift(np.fft.fft2(img)))
    n = width/2
    m = height/2

    #créé le figure
    plt.figure()
    #affiche l'axe à droite (l'échelle)
    ax = plt.axes(projection='3d')
    #initialise le tableau des x et des y
    x = np.arange(-n/height, n/height, float(fe/height))
    y = np.arange(-m/width,m/width, float(fe/width))
    X, Y = np.meshgrid(x, y)
    #affiche les dimensions de l'image
    print(X.shape)
    ax.plot_surface(X, Y, np.sqrt(f))
    #nome les axes
    plt.title({"Spectre - 1"})
    plt.xlabel("Fx")
    plt.ylabel("Fy")

    plt.figure()
    #affiche l'image
    plt.imshow(np.log(5*f+1),extent=[-n/height, n/height, -m/width,m/width])
    plt.colorbar()
    plt.xlabel("Fx")
    plt.ylabel("Fy")
    plt.title("Spectre - 2")



    ##Question 2
def binarisation_manuelle(seuil, image):
    largeur = len(image)
    longueur = len(image[1])

    nouvelle_image = np.zeros((largeur,longueur), dtype=int)

    for k in range(largeur):
        for i in range(longueur):
            if(image[k][i]>seuil):
                nouvelle_image[k][i] = 255
            else:
                nouvelle_image[k][i] = 0

    return nouvelle_image



if __name__ == "__main__":

    ##1.b
    f_1 = -0.3
    f_2 = 0.1
    f_e = 1

    img=atom(128,128,f_1,f_2);
    #affiche_image(img)
    #fourier2d(img,f_e)

    ##1.c
    rupt0=atom(128,128,0.05,0);
    rupt1=atom(128,128,0,0.05);
    rupt2=atom(128,128,0.05,0.05);

    #affiche_image(rupt0)
    #affiche_image(rupt1)
    #affiche_image(rupt2)

    #fourier2d(rupt0,f_e)
    #fourier2d(rupt1,f_e)
    #fourier2d(rupt2,f_e)

    ##1.d
    #Ouvre une image
    img = cv.imread("C:/Users/louka/Desktop/Cours/TP_Image/imagesTP/Leaves0012GP.png")
    img = cv.cvtColor(img,cv.COLOR_RGB2GRAY)

    #affiche_image(img)
    #fourier2d(img,f_e)

    ##2
    img = atom(128,128,0.15,0.37);
    #affiche_image(img)
    #fourier2d(img,f_e)

    #Utilise la fonction de binarisation du précédent TP
    img_binariser = binarisation_manuelle(0.5,img)
    #affiche_image(img_binariser)
    #fourier2d(img_binariser,f_e)

    image_redimensionner = img[::2, ::2]
    affiche_image(image_redimensionner)
    fourier2d(image_redimensionner,f_e)

    plt.show()