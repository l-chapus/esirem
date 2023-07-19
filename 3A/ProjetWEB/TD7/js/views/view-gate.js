import { Observer } from "./../patterns/observer.js"

/**
 * View responsible for the gate
 */
export class ViewGate extends Observer
{
    //Main controller
    #controllerGate;

    //Angle of the symbols on the gate
    #symbolsAngle;

    //Symbols moving speed
    #symbolsSpeed;

    //Displaying dimensions
    #gateOutsideSize;
    #gateInsideSize;
    #symboleWidth;
    #symboleHeight;

    /**
     * Constructor
     * @param {ControllerGate} controllerGate Controller responsible for the gate 
     */
    constructor(controllerGate)
    {
        super();

        this.#controllerGate = controllerGate;
        this.#controllerGate.addObserver(this);

        this.#symbolsAngle = 0;
        this.#symbolsSpeed = 10;

        this.#createSymbols();
        this.#initItemsSize();
        this.#updateSymbolsPosition(0);

        window.addEventListener("resize", () => { this.#initItemsSize()});
    }

    /**
     * Notification function
     */
    notify()
    {
        this.#updateGate();
    }

    /**
     * Creates the symbols on the gate
     */
    #createSymbols()
    {
        const symbols = document.querySelector("symbols");
        symbols.innerHTML = "";

        for(let i = 1; i <= 39; ++i)
        {
            const symbol = document.createElement("symbol");
            symbol.style.backgroundImage = `url(img/symbols/s${i}.png)`;

            symbols.appendChild(symbol);
        }
    }

    /**
     * Gets items displaying size
     */
    #initItemsSize()
    {
        this.#gateOutsideSize = document.querySelector("gate-outside")?.clientWidth;
        this.#gateInsideSize = document.querySelector("gate-inside")?.clientWidth;
        this.#symboleWidth = document.querySelector("symbol")?.clientWidth;
        this.#symboleHeight = document.querySelector("symbol")?.clientHeight;
    }

    /**
     * Updates gate status
     */
    #updateGate()
    {
        document.querySelector("gate").classList.toggle("active", this.#controllerGate.connected);
    }

    /**
     * Updates symbols position
     * @param {number} elapsedTime Elapsed time from the last update
     */
    #updateSymbolsPosition(elapsedTime)
    {
        const now = performance.now();

        const horizontalOffset = (this.#gateOutsideSize - this.#symboleWidth) / 2.0;
        const verticalOffset = (this.#gateOutsideSize - this.#symboleHeight) / 2.0;
        const finalOffset = (this.#gateOutsideSize + this.#gateInsideSize) / 4.0;

        this.#symbolsAngle += this.#symbolsSpeed * (elapsedTime / 1000.0);

        const symbols = document.querySelectorAll("symbol");
        symbols.forEach((symbol, index) => {
            symbol.style.transform = `translate(${horizontalOffset}px, ${verticalOffset}px) rotate(${(360.0 / 39.0) * (index) + this.#symbolsAngle}deg) translate(0, -${finalOffset}px)`
        });

        requestAnimationFrame(() => {
            this.#updateSymbolsPosition(performance.now() - now);
        })
    }
}