import { Notifier } from "../pattern/notifier.js";
import { Counter } from "../counter.js";

export class Controller extends Notifier
{
    #counter;
    constructor()
    {
        super();
        this.#counter = new Counter();
    }
    incrementCounter()
    {
        this.#counter.incrementValue();
        this.notify();
    }
    decrementCounter()
    {
        this.#counter.decrementValue();
        this.notify();
    }
    getCounterValue()
    {
        return this.#counter.number;
    }
}