import { Observer } from "../pattern/observer.js";

export class View extends Observer
{
    #controller;
    constructor(controller)
    {
        super();
        this.#controller = controller;
        this.#controller.addObserver(this);

        const incremnent = document.getElementById('btn-increment');
        incremnent.addEventListener("click",() => { 
            this.#controller.incrementCounter()
        });

        const decremnent = document.getElementById('btn-decrement');
        decremnent.addEventListener("click",() => {
            this.#controller.decrementCounter()
        });
    }
    notify()
    {
        const valeur = document.getElementById('txt-counter');
        valeur.innerText = this.#controller.getCounterValue();
    }
}