import tkinter as tk
import math
from tkinter import messagebox

def initWindow():
    window = tk.Tk()
    window.geometry("800x900")

    buttonAbout = tk.Button(
        window,
        text="About",
        width=10,
        height=2,
        command=buttonAboutClick,
    )
    buttonAbout.place(x=700, y=10)

    ## Frame pour les paramètres
    parameters_frame = tk.Frame(window, width=780, height=170, bd=2, relief=tk.SOLID)
    parameters_frame.place(x=10, y=60)

    parameter = tk.Label(
        window,
        text="Paramètres",
        width=10,
        height=5
    )
    parameter.place(x=20, y=20)
    order = tk.Label(
        parameters_frame,
        text="Order",
        width=10,
        height=3
    )
    order.place(x=150, y=5)

    ordeEntry = tk.Entry(
        parameters_frame,
        width=70,
    )
    ordeEntry.place(x=340, y=17)

    keepHistory = tk.Label(
        parameters_frame,
        text="Keep History",
        width=10,
        height=2
    )
    keepHistory.place(x=150, y=50)
    checkbox = tk.Checkbutton(
        parameters_frame,
        #variable=checkbox_var,
        #command=toggle_checkbox
    )
    checkbox.place(x=530, y=57)

    color = tk.Label(
        parameters_frame,
        text="Color",
        width=10,
        height=2
    )
    color.place(x=150, y=85)

    # Options de la liste déroulante
    optionsColors = ["Red", "Green", "Blue"]

    # Variable pour stocker l'option sélectionnée
    selectedColor = tk.StringVar(window)
    selectedColor.set(optionsColors[0])  # Option par défaut

    # Création de la liste déroulante
    colorMenu = tk.OptionMenu(
        window,
        selectedColor,
        *optionsColors,
    )
    colorMenu.place(x=520, y=145)

    speed = tk.Label(
        parameters_frame,
        text="Speed",
        width=10,
        height=2
    )
    speed.place(x=150, y=120)

    optionsSpeed = ["1", "2", "5", "10"]

    # Variable pour stocker l'option sélectionnée
    selectedSpeed = tk.StringVar(window)
    selectedSpeed.set(optionsSpeed[0])  # Option par défaut

    speedMenu = tk.OptionMenu(
        window,
        selectedSpeed,
        *optionsSpeed,
        #command=selectedSpeed
    )
    speedMenu.place(x=525, y=185)

    ##Canvas pour le dessin
    canvas = tk.Canvas(window, width=500, height=500, bg="white")
    canvas.place(x=130, y=240)

    ## Frame pour les opérations
    operation_frame = tk.Frame(window, width=780, height=70, bd=2, relief=tk.SOLID)
    operation_frame.place(x=10, y=770)

    operation_label = tk.Label(
        window,
        text="Opérations",
        width=10,
        height=2
    )
    operation_label.place(x=20, y=750)

    buttonExecute = tk.Button(
        operation_frame,
        text="Execute",
        width=32,
        height=2,
        command=lambda: execute_fractal(canvas, int(selectedSpeed.get()), selectedColor.get()),
    )
    buttonExecute.place(x=20, y=10)

    buttonErase = tk.Button(
        operation_frame,
        text="Erase",
        width=32,
        height=2,
        command=lambda: erase(canvas),
    )
    buttonErase.place(x=270, y=10)

    buttonExit = tk.Button(
        operation_frame,
        text="Exit",
        width=32,
        height=2,
        command=buttonAboutClick,
    )
    buttonExit.place(x=520, y=10)

    window.mainloop()


def buttonAboutClick():
    msg = messagebox.showinfo(
        title="A propos",
        message="Auteurs : CHAPUS Louka et AMOURA Adil\nAffiliation : Polytech Dijon\nDate de version : 10/02/2024\nNuméro de version : 2"
    )

def execute_fractal(canvas, order, color):
    canvas.delete("all")  # Efface le contenu du canvas avant de générer la fractale
    length = 400.0
    start_point = (50, 140)
    angle = 0
    # Générer la courbe de Koch pour chaque côté du flocon
    for _ in range(3):
        genererFloconKoch(canvas, order, length, start_point, angle, color)
        start_point = (start_point[0] + length * math.cos(angle), start_point[1] + length * math.sin(angle))
        angle += math.radians(120)


def genererFloconKoch(canvas, n, cote, start_point, angle, color):
    if n == 0:
        end_point = (
            start_point[0] + cote * math.cos(angle),
            start_point[1] + cote * math.sin(angle)  # Inversion de l'axe y
        )
        canvas.create_line(start_point, end_point, fill=color, width=2)
    else:
        cote /= 3.0
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color)
        start_point = (start_point[0] + cote * math.cos(angle), start_point[1] + cote * math.sin(angle))  # Inversion de l'axe y
        angle += math.radians(-60)
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color)
        start_point = (start_point[0] + cote * math.cos(angle), start_point[1] + cote * math.sin(angle))  # Inversion de l'axe y
        angle += math.radians(120)
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color)
        start_point = (start_point[0] + cote * math.cos(angle), start_point[1] + cote * math.sin(angle))  # Inversion de l'axe y
        angle += math.radians(-60)
        genererFloconKoch(canvas, n - 1, cote, start_point, angle, color)

def erase(canvas):
    canvas.delete("all")

initWindow()
