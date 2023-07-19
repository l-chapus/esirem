import { Observer } from "../patterns/observer.js";

/**
 * View responsible for the current sequence
 */
export class ViewSequence extends Observer
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
    }

    /**
     * Notification function
     */
    notify()
    {
        this.#displaySequence();
    }

    /**
     * Displays the current sequence
     */
    #displaySequence()
    {
        const sequences = document.querySelectorAll("sequence-symbol");

        sequences.forEach((sequence, index) =>
        {
            const img = (index < this.#controller.sequence.length ? `url(img/symbols/s${this.#controller.sequence[index]}.png)` : "none");
            sequence.style.backgroundImage = img;
        });
    }
}