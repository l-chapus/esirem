
import numpy as np

from matplotlib import pyplot as plt
import cv2 as cv

from scipy import signal



def histogramme(image):
    largeur = len(image)
    longueur = len(image[1])

    niveau_de_gris = [0 for k in range(256)]

    for k in range(largeur):
        for i in range(longueur):
            niveau_de_gris[image[k][i]] += 1

    return niveau_de_gris


def binarisation_manuelle(seuil, image):
    largeur = len(image)
    longueur = len(image[1])

    nouvelle_image =np.zeros((largeur,longueur), dtype=int)

    for k in range(largeur):
        for i in range(longueur):
            if(image[k][i]>seuil):
                nouvelle_image[k][i] = 255
            else:
                nouvelle_image[k][i] = 0

    return nouvelle_image


def binarisation_automatique(image_row):
    largeur = len(image_row)
    longueur = len(image_row[1])
    histo = histogramme(image_row)
    N = len(histo)
    mi = [0,0,0,0]

    print(N)
    print(longueur*largeur)

    for k in range(4):
        for i in range(len(histo)):
            mi[k] = mi[k] + (histo[i]**k)/N

    print(mi)

    C1 = (mi[2]*mi[1] - mi[3]*mi[0]) / (mi[2]*mi[0] - mi[1]*mi[1])
    C0 = -mi[2]/mi[0] - (C1*mi[1]) / mi[0]

    z0 = (-C1 + (C1*C1-4*C0)**(1/2))/2
    z1 = (-C1 - (C1*C1-4*C0)**(1/2))/2

    print(z0, z1)

    seuil = ((z0+z1)/2)

    print(seuil)

    nouvelle_image = np.zeros((largeur,longueur), dtype=int)

    for k in range(largeur):
        for i in range(longueur):
            if(image_row[k][i]>seuil):
                nouvelle_image[k][i] = 255
            else:
                nouvelle_image[k][i] = 0

    return nouvelle_image


def egalisation(image):
    histo = histogramme(image)
    Ymaxi = len(image)
    Xmaxi = len(image[1])
    Npixels = Ymaxi*Xmaxi
    kmaxi = len(histo)

    S=[0 for k in range(256)]

    S[0]=histo[0]

    for k in range(1,kmaxi):
        S[k] = S[k-1] + histo[k]

    for i in range(kmaxi):
        S[i] = (kmaxi - 1)*S[i]/Npixels


    nouvelle_image = np.zeros((Ymaxi,Xmaxi), dtype=int)
    gris = 0
    nouveau_bris = 0
    histo_egaliser=[0 for k in range(256)]

    for k in range(Ymaxi):
        for i in range(Xmaxi):
            gris = image[k][i]
            nouveau_gris=S[gris]
            nouvelle_image[k][i] = nouveau_gris

    absisse = [k for k in range(256)]

    plt.figure()
    plt.plot(absisse,S)

    plt.figure()
    plt.imshow(nouvelle_image, cmap="gray")


def filtrage(image):
    Robbert = np.array([[-1,0],[0,1]])
    Sobel = np.array([[1,0,-1],[2,0,-2],[1,0,-1]])
    Prewit = np.array([[1,0,-1],[1,0,-1],[1,0,-1]])


    filtre_Robbert = signal.convolve2d(image, Robbert, mode='same', boundary='fill')
    filtre_Sobel = signal.convolve2d(image, Sobel, mode='same', boundary='fill')
    filtre_Prewit = signal.convolve2d(image, Prewit, mode='same', boundary='fill')

    plt.figure()
    plt.subplot(2, 2, 1)
    plt.imshow(image, cmap="gray")
    plt.subplot(2, 2, 2)
    plt.imshow(filtre_Robbert, cmap="gray")
    plt.subplot(2, 2, 3)
    plt.imshow(filtre_Sobel, cmap="gray")
    plt.subplot(2, 2, 4)
    plt.imshow(filtre_Prewit, cmap="gray")



if __name__ == "__main__":


    #Ouvrir une image
    img = cv.imread("C:/Users/louka/Desktop/Cours/TP_Image/imagesTP/ligne_blanche.png")
    img = cv.cvtColor(img,cv.COLOR_BGR2RGB)

    #Afficher une image
    plt.figure()
    plt.imshow(img)

    #Afficher les canaux
    rouge = img[:,:, 0]
    vert = img[:,:, 1]
    bleu = img[:,:, 2]
    plt.figure()
    plt.subplot(2, 2, 1)
    plt.imshow(img)
    plt.subplot(2, 2, 2)
    plt.imshow(rouge, cmap="Reds")
    plt.subplot(2, 2, 3)
    plt.imshow(vert, cmap="Greens")
    plt.subplot(2, 2, 4)
    plt.imshow(bleu, cmap="Blues")

    # Transformation en niveau de gris
    imgG = cv.cvtColor(img,cv.COLOR_RGB2GRAY)
    plt.figure()
    plt.imshow(imgG, cmap="gray")


    histoGris = histogramme(imgG)
    absisse = [k for k in range(256)]

    plt.figure()
    plt.plot(absisse,histoGris)

    #image_binaire = binarisation_automatique(imgG)

    #plt.figure()
    #plt.imshow(image_binaire, cmap="gray")

    #egalisation(imgG)

    filtrage(imgG)

    plt.show()
