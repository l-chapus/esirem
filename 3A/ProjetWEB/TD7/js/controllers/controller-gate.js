import { Notifier } from "../patterns/notifier.js"

/**
 * Controller responsible for the gate
 */
export class ControllerGate extends Notifier
{
    //Sequence of activated symbols
    #sequence;
    get sequence() { return [...this.#sequence]; }

    //History of sequences enabling access to other planets
    #history;
    get history() { return [...this.#history]; }

    //Is the door connected to another one ?
    #connected;
    get connected() { return this.#connected; }

    /**
     * Constructor
     */
    constructor()
    {
        super();

        this.#sequence = [];
        this.#history = [];
        this.#connected = false;

        this.#loadHistory();
    }

    /**
     * Adds a symbol to the current sequence
     * @param {number} symboleId Id of the symbol to add 
     */
    addToSequence(symboleId)
    {
        if (this.#sequence.length < 7 && this.#sequence.indexOf(parseInt(symboleId)) === -1)
        {
            this.#sequence.push(symboleId);

            this.notify();

            if (this.#sequence.length === 7)
                this.#engage();
        }
    }

    /**
     * Clears the current sequence and close the door if connected
     */
    clearSequence()
    {
        this.#sequence.length = 0;
        this.#connected = false;

        this.notify();
    }

    /**
     * Tries to connect the door with the given sequence
     */
    async #engage()
    {
        const Data = JSON.stringify(this.#sequence);

        const formData = new FormData(); 
        formData.append("sequence", Data);

        const options = { 
            method: "POST",
            body: formData
        }; 
        
        const response = await fetch("http://51.83.35.197/api-stargate.php", options); 
        const textData = await response.text();

        if(textData != ""){
            this.#connected = true; 
            this.#addSequenceToHistory(textData);
        }
        else{
            this.#connected = false;
        }
        this.notify();
        
    }

    /**
     * Adds the current sequence to the history
     * @param {string} planetName Name of the planet that can be accessed using the current sequence 
     */
    #addSequenceToHistory(planetName)
    {
        this.#history.push = ({
            planet: planetName,
            sequence: this.#sequence
        });
     
        this.#saveHistory();

    }

    /**
     * Saves the history into the localStorage
     */
    #saveHistory()
    {
        localStorage.setItem("historique", this.#history);
        
    }

    /**
     * Loads the history from the localStorage
     */
    #loadHistory()
    {
        const historique = localStorage.getItem("historique");

        const Data = JSON.parse(historique);

        console.log(Data);
        
    }
}