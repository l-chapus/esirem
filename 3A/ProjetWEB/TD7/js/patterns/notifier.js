export class Notifier
{
    //Observers subscribed to the notifier
    #observers;

    /**
     * Constructor
     */
    constructor()
    {
        this.#observers = [];
    }

    /**
     * Subscribes an observer to the notifier
     * @param {Observer} observer Observe rto add 
     */
    addObserver(observer)
    {
        this.#observers.push(observer);
    }

    /**
     * Notifies all the subscribed observers
     */
    notify()
    {
        this.#observers.forEach((observer) => {
            observer.notify();
        })
    }
}