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

import math as m

#CODE IHSL
def convert_to_IHLS(image):
    R = image[:,:,0]
    G = image[:,:,1]
    B = image[:,:,2]

    H = np.zeros_like(image, dtype=np.uint8)
    L = np.zeros_like(image, dtype=np.uint8)
    S = np.zeros_like(image, dtype=np.uint8)


    largeur = len(image)
    longueur = len(image[1])

    for k in range(largeur):
        for i in range(longueur):
            r = R[k][i]
            g = G[k][i]
            b = B[k][i]

            denominator = m.sqrt(r**2 + g**2 + b**2 - r*g - r*b - b*g)

            if denominator == 0:
                H[k][i] = 0  # Valeur par défaut lorsque le dénominateur est égal à zéro
            else:
                H_prime = m.acos((r - g/2 - b/2) / denominator)
                H_prime = H_prime * 180 / m.pi

                if b > g:
                    H[k][i] = 360 - H_prime
                else:
                    H[k][i] = H_prime

            L[k][i] = 0.2126*r +0.7152*g+0.0722*b
            S[k][i] = max(r,g,b) - min(r,g,b)


    return H,L,S



if __name__ == "__main__":

    ##1.1
    #Ouvre une image
    #img = cv.imread("C:/Users/louka/Desktop/Github/esirem/3A/TP_Image/imagesTP/confiserie-smarties-lentilles_121-50838.jpg")
    #img = cv.imread("C:/Users/louka/Desktop/Github/esirem/3A/TP_Image/imagesTP/coquelicots.jpg")
    #img = cv.cvtColor(img,cv.COLOR_BGR2HSV)
    #plt.figure()
    #plt.imshow(img, cmap="hsv")
    #plt.colorbar()

    ##1.2
    #Affichage des images

    # Extraction des composantes HSL
    # hue = img[:, :, 0]  # Composante teinte
    # lightness = img[:, :, 1]  # Composante luminosité/clarté
    # saturation = img[:, :, 2]  # Composante saturation
    #
    #
    # cv.imshow('Lightness/Clarity Image', lightness)
    # cv.imshow('Saturation Image', saturation)
    # cv.waitKey(0)
    # cv.destroyAllWindows()
    #
    # plt.figure()
    # plt.imshow(hue, cmap="hsv")
    #
    # plt.show()


    ##1.3
    # H,L,S = convert_to_IHLS(img)
    #
    # cv.imshow('Lightness/Clarity Image', L)
    # cv.imshow('Saturation Image', S)
    # cv.imshow('Hue', H)
    # cv.waitKey(0)
    # cv.destroyAllWindows()
    #
    # plt.show()

    ##2.a.1
    # image = cv.imread("C:/Users/louka/Desktop/Github/esirem/3A/TP_Image/imagesTP/confiserie-smarties-lentilles_121-50838.jpg")
    #
    # #Conversion de l'image en espace de couleur BGR
    # image_bgr = image.copy()
    #
    # #extraction canal bleu
    # blue_channel = image_bgr[:, :, 0]
    # red_channel = image_bgr[:, :, 2]
    #
    #
    #
    # #Seuillage pour ne garder que le bleu
    # #, blue_threshold = cv.threshold(image_bgr[:, :, 0], 230, 255, cv.THRESH_BINARY)
    #
    # blue_mask = np.logical_and(blue_channel > 220, red_channel < 130)
    #
    #
    # #Création d'une image masquée avec seulement les pixels bleus
    # #masked_image = cv.bitwise_and(image, image, mask=blue_threshold)
    #
    # masked_image = np.zeros_like(image_bgr)
    # masked_image[blue_mask] = image_bgr[blue_mask]
    #
    # # Extraction des canaux rouge et vert de l'image BGR
    # red_channel = image_bgr[:, :, 2]
    # green_channel = image_bgr[:, :, 1]
    #
    # #Création d'un masque pour les pixels jaunes
    # yellow_mask = np.logical_and(red_channel > 220, green_channel > 220)
    #
    # #Création d'une image masquée avec seulement les pixels jaunes
    # masked_image2 = np.zeros_like(image_bgr)
    # masked_image2[yellow_mask] = image_bgr[yellow_mask]
    #
    # #Affichage de l'image originale et de l'image masquée
    # cv.imshow('Original Image', image)
    # cv.imshow('Masked Image (Blue)', masked_image)
    # cv.imshow('Masked Image (yellow)', masked_image2)
    # cv.waitKey(0)
    # cv.destroyAllWindows()
    #
    #
    # #Extraction des canaux BGR
    # blue_channel = image_bgr[:, :, 0]
    # red_channel = image_bgr[:, :, 2]
    #
    # #Création du masque initial pour les pixels bleus
    # initial_mask = np.logical_and(blue_channel > 220, red_channel < 130)
    #
    # #Opération d'ouverture pour éliminer les petits bruits
    # kernel_open = np.ones((5, 5), np.uint8)
    # opened_mask = cv.morphologyEx(initial_mask.astype(np.uint8), cv.MORPH_OPEN, kernel_open)
    #
    # #Opération de fermeture pour fermer les petits et grands trous
    # kernel_close = np.ones((15, 15), np.uint8)
    # closed_mask = cv.morphologyEx(opened_mask, cv.MORPH_CLOSE, kernel_close)
    #
    # #Création d'une image masquée avec seulement les pixels bleus améliorés
    # masked_image = cv.bitwise_and(image_bgr, image_bgr, mask=closed_mask.astype(np.uint8))
    #
    # #Affichage de l'image originale, du masque initial et de l'image masquée améliorée
    # cv.imshow('Masked Image (Improved)', masked_image)
    # cv.waitKey(0)
    # cv.destroyAllWindows()


    ## 2.a.4

    # image_bgr = cv.imread(r"C:/Users/louka/Desktop/Github/esirem/3A/TP_Image/imagesTP/coquelicots.jpg")
    #
    # #Conversion de l'image en espace HSV
    # image_hsv = cv.cvtColor(image_bgr, cv.COLOR_BGR2HSV)
    #
    # plt.figure()
    # plt.imshow(image_hsv[:, :, 0], cmap="hsv")
    # plt.colorbar()
    # plt.show()
    #
    # #Définition de la plage de teinte pour le bleu
    # lower_blue = np.array([10, 50, 50])
    # upper_blue = np.array([30, 255, 255])
    #
    # #Création du masque pour les pixels bleus
    # blue_mask = cv.inRange(image_hsv, lower_blue, upper_blue)
    #
    # inverse_mask = cv.bitwise_not(blue_mask)
    #
    # #Application du masque à l'image originale
    # mask_sky = cv.bitwise_and(image_bgr, image_bgr, mask=inverse_mask)
    #
    #
    #
    # #Affichage de l'image originale et de l'image avec le ciel bleu filtré
    # cv.imshow("Original Image", image_bgr)
    # cv.imshow("image ciel filtré", mask_sky)
    #
    # cv.waitKey(0)
    # cv.destroyAllWindows()

    ## 2.a.6
    # Chargement de l'image
    # image_bgr = cv.imread(r"C:/Users/louka/Desktop/Github/esirem/3A/TP_Image/imagesTP/CerisierP.jpg")
    #
    # Conversion de l'image en espace HSV
    # image_hsv = cv.cvtColor(image_bgr, cv.COLOR_BGR2HSV)
    #
    # plt.figure()
    # plt.imshow(image_hsv[:, :, 0], cmap="hsv")
    # plt.colorbar()
    # plt.show()
    #
    # # Définition de la plage de teinte pour le bleu
    # lower_blue = np.array([100, 50, 50])
    # upper_blue = np.array([130, 255, 255])
    #
    # # Création du masque pour les pixels bleus
    # blue_mask = cv.inRange(image_hsv, lower_blue, upper_blue)
    #
    # # Application du masque au canal rouge et au canal vert pour les modifier en rouge
    # image_bgr[:, :, 0] = np.where(blue_mask > 0, 0, image_bgr[:, :, 0])  # Canal bleu
    # image_bgr[:, :, 1] = np.where(blue_mask > 0, 0, image_bgr[:, :, 1])  # Canal vert
    #
    #
    # # Affichage de l'image originale et de l'image avec le ciel bleu filtré
    # cv.imshow("Original Image", image_bgr)
    #
    #
    # cv.waitKey(0)
    # cv.destroyAllWindows()










