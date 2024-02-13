import tkinter as tk
import math
from tkinter import messagebox      # Importation de la classe messagebox pour afficher des boîtes de dialogue
import time

def main():
    # Initialiser et afficher la fenêtre principale
    window = initWindow()

def initWindow():
    window = tk.Tk()               # Création d'une instance de la classe Tk pour la fenêtre principale
    window.geometry("800x900")     # Définition de la taille de la fenêtre

    # Création du bouton "About"
    buttonAbout = tk.Button(
        window,
        text="About",               # Texte affiché sur le bouton
        width=10,                   # Largeur du bouton
        height=2,                   # Hauteur du bouton
        command=buttonAboutClick,   # Fonction appelée lors du clic sur le bouton
    )
    buttonAbout.place(x=700, y=10) # Positionnement du bouton dans la fenêtre

    ## Frame pour les paramètres
    parameters_frame = tk.Frame(window, width=780, height=170, bd=2, relief=tk.SOLID)  # Création d'un cadre pour les paramètres
    parameters_frame.place(x=10, y=60)                                                 # Positionnement du cadre dans la fenêtre

    # Labels pour les paramètres
    parameter = tk.Label(
        window,
        text="Paramètres",         # Texte affiché
        width=10,                  # Largeur
        height=5                   # Hauteur
    )
    parameter.place(x=20, y=20)    # Positionnement

    order = tk.Label(
        parameters_frame,
        text="Order",               # Texte affiché
        width=10,                   # Largeur
        height=3                    # Hauteur
    )
    order.place(x=150, y=5)         # Positionnement

    # Variable d'entier pour stocker la valeur de l'entrée "Order"
    order = tk.IntVar(value=1)

    # Entrée pour l'ordre
    orderEntry = tk.Entry(
        parameters_frame,
        width=70,
        textvariable=order,         # Lier la variable d'entier à l'entrée
    )
    orderEntry.place(x=340, y=17)  # Positionnement de l'entrée

    keepHistory = tk.Label(
        parameters_frame,
        text="Keep History",        # Texte affiché
        width=10,                   # Largeur
        height=2                    # Hauteur
    )
    keepHistory.place(x=150, y=50)  # Positionnement

    # Variable d'entier pour la case à cocher et initialisation à 0
    checkboxHistory = tk.IntVar(value=0)

    # Case à cocher pour l'historique
    checkbox = tk.Checkbutton(
        parameters_frame,
        variable=checkboxHistory,   # Lier la variable d'entier à la case à cocher
    )
    checkbox.place(x=530, y=57)     # Positionnement de la case à cocher

    # Label pour la couleur
    color = tk.Label(
        parameters_frame,
        text="Color",               # Texte affiché
        width=10,                   # Largeur
        height=2                    # Hauteur
    )
    color.place(x=150, y=85)        # Positionnement

    # Options de couleurs
    optionsColors = ["Red", "Green", "Blue"]

    # Variable de chaîne pour stocker la couleur sélectionnée
    selectedColor = tk.StringVar(window)
    selectedColor.set(optionsColors[0])  # Option par défaut

    # Liste déroulante pour sélectionner la couleur
    colorMenu = tk.OptionMenu(
        window,
        selectedColor,
        *optionsColors,
    )
    colorMenu.place(x=520, y=145)    # Positionnement de la liste déroulante

    # Label pour la vitesse
    speed = tk.Label(
        parameters_frame,
        text="Speed",               # Texte affiché
        width=10,                   # Largeur
        height=2                    # Hauteur
    )
    speed.place(x=150, y=120)        # Positionnement

    # Options de vitesse
    optionsSpeed = ["5", "10", "20", "50", "200", "1000", "10000"]

    # Variable de chaîne pour stocker la vitesse sélectionnée
    selectedSpeed = tk.StringVar(window)
    selectedSpeed.set(optionsSpeed[0])  # Option par défaut

    # Liste déroulante pour sélectionner la vitesse
    speedMenu = tk.OptionMenu(
        window,
        selectedSpeed,
        *optionsSpeed,
    )
    speedMenu.place(x=525, y=185)    # Positionnement de la liste déroulante

    ##Canvas pour le dessin
    canvas = tk.Canvas(window, width=500, height=500, bg="white")  # Création du canevas
    canvas.place(x=130, y=240)                                    # Positionnement du canevas dans la fenêtre

    ## Frame pour les opérations
    operation_frame = tk.Frame(window, width=780, height=70, bd=2, relief=tk.SOLID)   # Création d'un cadre pour les opérations
    operation_frame.place(x=10, y=770)                                                # Positionnement du cadre dans la fenêtre

    # Label pour les opérations
    operation_label = tk.Label(
        window,
        text="Opérations",          # Texte affiché
        width=10,                   # Largeur
        height=2                    # Hauteur
    )
    operation_label.place(x=20, y=750)    # Positionnement

    # Bouton "Execute" pour exécuter l'action
    buttonExecute = tk.Button(
        operation_frame,
        text="Execute",             # Texte affiché sur le bouton
        width=32,                   # Largeur du bouton
        height=2,                   # Hauteur du bouton
        command=lambda: executeFractal(canvas, int(order.get()), selectedColor.get(), checkboxHistory.get(), int(selectedSpeed.get())),
    )
    buttonExecute.place(x=20, y=10)    # Positionnement du bouton

    # Bouton "Erase" pour effacer le canevas
    buttonErase = tk.Button(
        operation_frame,
        text="Erase",               # Texte affiché sur le bouton
        width=32,                   # Largeur du bouton
        height=2,                   # Hauteur du bouton
        command=lambda: erase(canvas),
    )
    buttonErase.place(x=270, y=10)    # Positionnement du bouton

    # Bouton "Exit" pour quitter l'application
    buttonExit = tk.Button(
        operation_frame,
        text="Exit",                # Texte affiché sur le bouton
        width=32,                   # Largeur du bouton
        height=2,                   # Hauteur du bouton
        command=lambda: exitApplication(window),
    )
    buttonExit.place(x=520, y=10)    # Positionnement du bouton

    window.mainloop()                 # Lancer la boucle principale de l'interface graphique

# Fonction appelée lors du clic sur le bouton "About"
def buttonAboutClick():
    msg = messagebox.showinfo(
        title="A propos",
        message="Auteurs : CHAPUS Louka et AMOURA Adil\nAffiliation : Polytech Dijon\nDate de version : 13/02/2024\nNuméro de version : 5"
    )

# Fonction pour exécuter la fractale
def executeFractal(canvas, order, color, checkboxHistory, speed):
    if order >= 0:
        if not checkboxHistory:
            erase(canvas)           # Effacer le contenu du canevas avant de générer la fractale

        length = 400.0
        start_point = (50, 140)
        angle = 0
        timeSleep = 1/speed

        # Générer la courbe de Koch pour chaque côté du flocon
        for _ in range(3):
            genererFloconKoch(canvas, order, length, start_point, angle, color, timeSleep)
            start_point = (start_point[0] + length * math.cos(angle), start_point[1] + length * math.sin(angle))
            angle += math.radians(120)

# Fonction récursive pour générer la fractale de Koch
def genererFloconKoch(canvas, n, cote, start_point, angle, color, sleep):
    if n == 0:
        end_point = (
            start_point[0] + cote * math.cos(angle),
            start_point[1] + cote * math.sin(angle)  # Inversion de l'axe y
        )
        canvas.create_line(start_point, end_point, fill=color, width=2)  # Dessiner la ligne
        canvas.update()  # Mettre à jour le canevas pour afficher le tracé
        time.sleep(sleep)   # Pause pour l'animation
    else:
        cote /= 3.0
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color, sleep)
        start_point = (start_point[0] + cote * math.cos(angle), start_point[1] + cote * math.sin(angle))  # Inversion de l'axe y
        angle += math.radians(-60)
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color, sleep)
        start_point = (start_point[0] + cote * math.cos(angle), start_point[1] + cote * math.sin(angle))  # Inversion de l'axe y
        angle += math.radians(120)
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color, sleep)
        start_point = (start_point[0] + cote * math.cos(angle), start_point[1] + cote * math.sin(angle))  # Inversion de l'axe y
        angle += math.radians(-60)
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color, sleep)

# Fonction pour effacer le canevas
def erase(canvas):
    canvas.delete("all")

# Fonction pour quitter l'application
def exitApplication(window):
    if messagebox.askokcancel("Quitter", "Voulez-vous vraiment quitter l'application ?"):
        window.destroy()

# Point d'entrée du programme
if __name__ == "__main__":
    main()
