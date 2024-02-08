import tkinter as tk
import math
#from tkinter import messagebox

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
    optionsColors = ["Select", "Red", "Green", "Blue"]

    # Variable pour stocker l'option sélectionnée
    selected_color = tk.StringVar(window)
    selected_color.set(optionsColors[0])  # Option par défaut

    # Création de la liste déroulante
    colorMenu = tk.OptionMenu(
        window,
        selected_color,
        *optionsColors,
        command=selected_color
    )
    colorMenu.place(x=510, y=145)

    speed = tk.Label(
        parameters_frame,
        text="Speed",
        width=10,
        height=2
    )
    speed.place(x=150, y=120)

    optionsSpeed = ["5", "10", "15", "120"]

    # Variable pour stocker l'option sélectionnée
    selectedSpeed = tk.StringVar(window)
    selectedSpeed.set(optionsSpeed[0])  # Option par défaut

    speedMenu = tk.OptionMenu(
        window,
        selectedSpeed,
        *optionsSpeed,
        command=selectedSpeed
    )
    speedMenu.place(x=525, y=185)

    ##Canvas pour le dessin
    canvas = tk.Canvas(window, width=500, height=500, bg="white")
    canvas.place(x=10, y=240)

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
        #command=execute_fractal(canvas,selectedSpeed,selected_color),
    )
    buttonExecute.place(x=20, y=10)
    buttonErase = tk.Button(
        operation_frame,
        text="Erase",
        width=32,
        height=2,
        command=buttonAboutClick,
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
        message="Auteurs : CHAPUS Louka et AMOURA Adil\nAffiliation : Polytech Dijon\nDate de version : 08/02/2024\nNuméro de version : 1"
    )

def execute_fractal(canvas, order, color):
    canvas.delete("all")  # Efface le contenu du canvas avant de générer la fractale
    length = 400.0
    start_point = (10, 200)
    angle = 0
    generer_flocon_koch(canvas, order, length, start_point, angle, color)

def generer_flocon_koch(canvas, order, length, start_point, angle, color):
    if order == 0:
        end_point = (
            start_point[0] + length * math.cos(angle),
            start_point[1] + length * math.sin(angle)
        )
        canvas.create_line(start_point, end_point, fill=color, width=2)
    else:
        third_length = length / 3.0

        p1 = start_point
        p2 = (
            p1[0] + third_length * math.cos(angle),
            p1[1] + third_length * math.sin(angle)
        )

        p3 = (
            p2[0] + third_length * math.cos(angle - math.pi / 3),
            p2[1] + third_length * math.sin(angle - math.pi / 3)
        )

        p4 = (
            p3[0] + third_length * math.cos(angle + math.pi / 3),
            p3[1] + third_length * math.sin(angle + math.pi / 3)
        )

        p5 = (
            p4[0] + third_length * math.cos(angle),
            p4[1] + third_length * math.sin(angle)
        )

        generer_flocon_koch(canvas, order - 1, third_length, p1, angle, color)
        generer_flocon_koch(canvas, order - 1, third_length, p2, angle - math.pi / 3, color)
        generer_flocon_koch(canvas, order - 1, third_length, p3, angle + math.pi / 3, color)
        generer_flocon_koch(canvas, order - 1, third_length, p4, angle - math.pi / 3, color)
        generer_flocon_koch(canvas, order - 1, third_length, p5, angle, color)

initWindow()
