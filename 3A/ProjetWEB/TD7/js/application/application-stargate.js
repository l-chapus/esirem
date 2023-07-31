import { ControllerGate } from "../controllers/controller-gate.js";
import { ViewGate } from "../views/view-gate.js";
import { ViewKeyboard } from "../views/view-keyboard.js";
import { ViewSequence } from "../views/view-sequence.js";

/**
 * Stargate application
 */
export class ApplicationStargate
{
    //Main controller of the application
    #controllerGate;

    //View responsible for the gate
    #viewGate;

    //View responsible for the keyboard
    #viewKeyboard;

    //View responsible for the sequence
    #viewSequence;

    /**
     * Constructor
     */
    constructor()
    {
        this.#controllerGate = new ControllerGate();
        this.#viewGate = new ViewGate(this.#controllerGate);
        this.#viewKeyboard = new ViewKeyboard(this.#controllerGate);
        this.#viewSequence = new ViewSequence(this.#controllerGate);

        this.#controllerGate.notify();
    }
}