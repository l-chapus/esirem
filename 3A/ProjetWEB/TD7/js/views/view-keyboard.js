import { Observer } from "./../patterns/observer.js"

/**
 * View responsible for the keyboard
 */
export class ViewKeyboard extends Observer
{
    //Controller responsible for the gate
    #controller;

    /**
     * Constructor
     * @param {ControllerGate} controller Controller responsible for the gate
     */
    constructor(controller)
    {
        super();

        this.#controller = controller;
        this.#controller.addObserver(this);

        this.#createKeyboard();
    }

    /**
     * Notification function
     */
    notify()
    {
        this.#updateKeyboard();
    }

    /**
     * Creates keys of the keyboard
     */
    #createKeyboard()
    {
        const keyboard = document.querySelector("keyboard");
        keyboard.innerHTML = "";

        for (let i = 1; i <= 39; ++i)
        {
            const key = document.createElement("keyboard-symbol");
            key.style.backgroundImage = `url(img/symbols/s${i}.png)`;
            key.dataset.id = i;

            key.addEventListener("click", () => { this.#controller.addToSequence(i) });

            keyboard.appendChild(key);
        }

        const key = document.createElement("keyboard-symbol");
        key.innerText = "Abort";
        key.addEventListener("click", () => { this.#controller.clearSequence() });
        keyboard.appendChild(key);
    }

    /**
     * Updates keys status
     */
    #updateKeyboard()
    {
        const keys = document.querySelectorAll("keyboard-symbol");
        keys.forEach((key) =>
        {
            if (this.#controller.sequence.indexOf(parseInt(key.dataset.id)) !== -1)
                key.classList.add("active");
            else
                key.classList.remove("active");
        });
    }
}