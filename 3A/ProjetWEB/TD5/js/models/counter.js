export class Counter
{
    #number;
    constructor()
    {
        this.#number = 0;
    }

    get number() 
    {
        return this.#number 
    }
    incrementValue()
    {
        this.#number = this.#number + 1;
    }

    decrementValue()
    {
        this.#number = this.#number - 1;
    }
}